#include "ThreadHandler.hpp"

//<<constructor>>
ThreadHandler::ThreadHandler() {}

//<<destructor>>
ThreadHandler::~ThreadHandler() {}

// get the list of queued animation threads
std::vector<AnimationThread*> ThreadHandler::listAnimationThreads() { return anim_threads; }

// get the list of queued process threads
std::vector<ProcessThread*> ThreadHandler::listProcessThreads() { return proc_threads; }

// queue an animation
void ThreadHandler::queue(Animation* anim) {
	anim->init();

	// dequeue conflicting threads
	dequeueConflicts(anim);

	// queue this animation as a new thread (set current time as the update rate so it initially sets on start)
	AnimationThread* t = new AnimationThread(next_id, anim);
	next_id++;

	anim_threads.push_back(t);

	Serial.print(F("ThreadHandler.cpp:> New Animation Thread Queued: "));
	Serial.print(anim->getName());
	Serial.print(F(" at "));
	Serial.print(anim->getUpdateRate());
	Serial.print(F(" mHz"));
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	mem_available = freeMemory();
}

// queue a process
void ThreadHandler::queue(Process* proc) {
	// queue this process as a new thread (set current time as the update rate so it initially sets on start)
	ProcessThread* t = new ProcessThread(next_id, proc);
	next_id++;

	proc_threads.push_back(t);

	Serial.print(F("ThreadHandler.cpp:> New Process Thread Queued: "));
	Serial.print(proc->getName());
	Serial.print(F(" at "));
	Serial.print(proc->getUpdateRate());
	Serial.print(F(" mHz"));
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	mem_available = freeMemory();
}

// update the time sums for each animation thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT) {
	// iterate through each queued thread
	for (std::vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++) {
		Thread& this_thread = **it;
		this_thread.addTimeSum(dT);
	}

	// iterate through each queued process thread
	for (std::vector<ProcessThread*>::iterator it = proc_threads.begin(); it != proc_threads.end(); it++) {
		Thread& this_thread = **it;
		this_thread.addTimeSum(dT);
	}
}

// execute a tick of the handler
void ThreadHandler::executeTick() {
	int i = 0;

	// iterate through each queued animation thread
	for (std::vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++, i++) {
		AnimationThread& this_thread = **it;
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
			anim_threads.erase(anim_threads.begin() + i);
		}
	}

	// iterate through each queued process thread
	for (std::vector<ProcessThread*>::iterator it = proc_threads.begin(); it != proc_threads.end(); it++) {
		ProcessThread& this_thread = **it;
		unsigned long int updateRate = this_thread.getUpdateRate();
		unsigned long int timeSum = this_thread.getTimeSum();

		if (timeSum >= updateRate || this_thread.checkFirstCall()) {
			this_thread.getProcess()->run();
			this_thread.zeroTimeSum();
		}
	}
}

// dequeue any conflicts (recursive)
void ThreadHandler::dequeueConflicts(Animation* anim) {
	int i = 0;

	for (std::vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++, i++) {
		AnimationThread& this_thread = **it;

		if (conflictsWith(anim->getDependencies(), anim->getNumStrips(), this_thread.getAnimation()->getDependencies(), this_thread.getAnimation()->getNumStrips())) {
			Serial.print(F("ThreadHandler.cpp:> Conflicting Function De-Queued: "));
			Serial.println(this_thread.getAnimation()->getName());

			delete *it;
			anim_threads.erase(anim_threads.begin() + i);

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
