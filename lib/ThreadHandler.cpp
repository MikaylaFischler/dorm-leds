#include "ThreadHandler.hpp"
#include "../util/mem.c"
#include "../util/MemoryFree.h"

//<<constructor>>
ThreadHandler::ThreadHandler() {}

//<<destructor>>
ThreadHandler::~ThreadHandler() {}

// get the list of queued threads
std::vector<Thread*> ThreadHandler::listThreads() { return threads; }

// queue an animation
void ThreadHandler::queue(Animation* anim) {
	anim->init();

	// dequeue conflicting threads
	dequeueConflicts(anim);

	// queue this command as a new thread (set current time as the update rate so it initially sets on start)
	Thread* t = new Thread(next_id, anim);
	next_id++;

	threads.push_back(t);

	Serial.print(F("ThreadHandler.cpp:> New Thread Queued: "));
	Serial.print(anim->getName());
	Serial.print(F(" at "));
	Serial.print(anim->getUpdateRate());
	Serial.print(F(" mHz"));
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	mem_available = freeMemory();
}

// update the time sums for each thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT) {
	// iterate through each queued thread
	for (std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++) {
		Thread& this_thread = **it;
		this_thread.addTimeSum(dT);
	}
}

// execute a tick of the handler
void ThreadHandler::executeTick() {
	int i = 0;

	// iterate through each queued thread
	for (std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++, i++) {
		Thread& this_thread = **it;
		unsigned long int updateRate = this_thread.getUpdateRate();
		unsigned long int timeSum = this_thread.getTimeSum();

		if (timeSum >= updateRate || this_thread.checkFirstCall()) {
			this_thread.getAnimation()->step();
			this_thread.zeroTimeSum();
		}

		long int max_exec = this_thread.getAnimation()->getMaxExecutions();
		long int current_exec = this_thread.getAnimation()->getCurrentExecutionCount();

		if (max_exec != -1 && current_exec >= max_exec) {
			delete *it;
			threads.erase(threads.begin() + i);
		}
	}
}

// dequeue any conflicts (recursive)
void ThreadHandler::dequeueConflicts(Animation* anim) {
	int i = 0;

	for (std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++, i++) {
		Thread& this_thread = **it;

		if (conflictsWith(anim->getDependencies(), anim->getNumStrips(), this_thread.getAnimation()->getDependencies(), this_thread.getAnimation()->getNumStrips())) {
			Serial.print(F("ThreadHandler.cpp:> Conflicting Function De-Queued: "));
			Serial.println(this_thread.getAnimation()->getName());

			delete *it;
			threads.erase(threads.begin() + i);

			dequeueConflicts(anim);
			break;
		}
	}
}

// check if the inputed list conflicts another inputed list
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
bool ThreadHandler::conflictsWith(short int* str1, int length1, short int* str2, int length2) {
	for (int a = 0; a < length1; a++) {
		for (int b = 0; b < length2; b++) {
			if (str1[a] == str2[b]) {
				return true;
			}
		}
	}

	return false;
}
