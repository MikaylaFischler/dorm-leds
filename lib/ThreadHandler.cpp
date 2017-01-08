#include "ThreadHandler.h"

//<<constructor>>
ThreadHandler::ThreadHandler() {}

//<<destructor>>
ThreadHandler::~ThreadHandler() {}

// get the list of queued threads
std::vector<Thread&> ThreadHandler::listThreads() { return threads; }

// queue an animation
void ThreadHandler::queue(Animation& anim) {
	dequeueConflicts(anim);
	setStripsInUse(anim);

	// queue this command as a new thread (set current time as the update rate so it initially sets on start)
	Thread& t = Thread(next_id, anim, anim.getUpdateRate());
	next_id++;

	threads.push_back(t);

	Serial.println(F("ThreadHandler.cpp:> New Thread Queued: " + anim.getName());
}

// update the time sums for each thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT) {
	// iterate through each queued thread
	for(std::vector<Thread&>::iterator it = threads.begin(); it != threads.end(); it++){
		Thread& this_thread = *it;
		this_thread.addTimeSum(dT);
	}
}

// execute a tick of the handler
void ThreadHandler::executeTick() {
	// iterate through each queued thread
	for (std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++) {
		Thread& this_thread = *it;
		unsigned long int updateRate = this_thread.getUpdateRate();
		unsigned long int timeSum = this_thread.getTimeSum();

		if(timeSum >= updateRate){
			this_thread.getAnimation().step();
			this_thread.zeroTimeSum();
		}
	}
}

// update the list of strips in use
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
void ThreadHandler::setStripsInUse(Animation& anim) {
	int* str = anim.getDependencies();
	int length = anim.getNumStrips();

	for (int i = 0; i < length; i++) {
		for (int y = 0; y < 5; y++) {
			if (str[i] == this->strip_status[y][0]) {
				this->strip_status[y][1] = STRIP_ON;
			}
		}
	}
}

// dequeue any conflicts (recursive)
void ThreadHandler::dequeueConflicts(Animation& anim) {
	int i = 0;

	for (std::vector<Thread&>::iterator it = threads.begin(); it != threads.end(); it++, i++) {
		Thread& this_thread = *it;

		if (conflictsWith(anim.getDependencies(), anim.getNumStrips(), this_thread.getAnimation().getDependencies(), this_thread.getAnimation().getNumStrips()) {
			threads.erase(threads.begin() + i);
			Serial.println("ThreadHandler.cpp:> Conflicting Function De-Queued: " + this_thread.getAnimation().getName());

			dequeueConflicts(anim);
			break;
		}
	}
}

// check if the inputed list conflicts another inputed list
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
bool ThreadHandler::conflictsWith(int* str1, int length1, int* str2, int length2) {
	for (int a = 0; a < length1; a++) {
		for (int b = 0; b < length2; b++) {
			if (str1[a] == str2[b]) {
				return true;
			}
		}
	}

	return false;
}
