#include "ThreadHandler.hpp"

// get the list of queued animation threads
vector<AnimationThread*> ThreadHandler::listAnimationThreads() const { return anim_threads; }

// get the list of queued process threads
vector<ProcessThread*> ThreadHandler::listProcessThreads() const { return proc_threads; }

// queue an animation
void ThreadHandler::queue(Animation* anim) {
	anim->init();

	// queue this animation as a new thread (set current time as the update rate so it initially sets on start)
	AnimationThread* t = new AnimationThread(next_id, anim);
	next_id++;

	// console output
	Serial.print(F("ThreadHandler.cpp:> New Animation Thread Generated: "));
	Serial.print(anim->getName());
	Serial.print(F(" at "));
	Serial.print(anim->getUpdateRate());
	Serial.print(F(" mHz"));
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	vector<int> dependencies = anim->getDependencies();
	vector<Animation*> conflicts;

	// check for conflicting animations
	for (unsigned int i = 0; i < dependencies.size(); i++) {
		if (npsm.inUse(dependencies[i])) {
			conflicts.push_back(npsm.usedBy(dependencies[i]));
		}
	}

	// de-queue conflicting animations
	for (unsigned int i = 0; i < conflicts.size(); i++) {
		int x = 0;
		for (vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++, x++) {
			if ((*it)->getAnimation() == conflicts[i]) {
				Serial.print(F("ThreadHandler.cpp:> De-queuing conflict: "));
				Serial.println((*it)->getAnimation()->getName());

				vector<int> depend = anim->getDependencies();

				// release the strips used by this animation
				for (unsigned int i = 0; i < depend.size(); i++) {
					npsm.release(depend[i]);
				}

				// delete this animation
				delete *it;
				anim_threads.erase(anim_threads.begin() + x);

				Serial.print(F("ThreadHandler.cpp:> Conflicting Function De-Queued."));
			}
		}
	}

	// attain owndership of necessary strips
	for (unsigned int i = 0; i < dependencies.size(); i++) {
		npsm.use(dependencies[i], anim);
	}

	anim_threads.push_back(t);

	Serial.println(F("ThreadHandler.cpp:> Animation Thread Queued."));

	mem_available = freeMemory();
}

// queue a process
void ThreadHandler::queue(Process* proc) {
	proc->init();

	// queue this process as a new thread (set current time as the update rate so it initially sets on start)
	ProcessThread* t = new ProcessThread(next_id, proc);
	next_id++;

	proc_threads.push_back(t);

	// console output
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

// update the time sums for each thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT) {
	// iterate through each queued animation thread
	for (vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++) {
		(*it)->addTime(dT);;
	}

	// iterate through each queued process thread
	for (vector<ProcessThread*>::iterator it = proc_threads.begin(); it != proc_threads.end(); it++) {
		(*it)->addTime(dT);
	}
}

// execute a tick of the handler (step all threads)
void ThreadHandler::executeTick() {
	int i = 0;

	unsigned long int updateRate;
	unsigned long int timeSum;

	// iterate through each queued animation thread
	for (vector<AnimationThread*>::iterator it = anim_threads.begin(); it != anim_threads.end(); it++, i++) {
		AnimationThread& this_thread = **it;
		updateRate = this_thread.getUpdateRate();
		timeSum = this_thread.getTimeSum();

		if (timeSum >= updateRate || this_thread.checkFirstCall()) {
			this_thread.getAnimation()->step();
			this_thread.resetTimeSum();
		}

		long int max_exec = this_thread.getAnimation()->getMaxExecutions();
		long int current_exec = this_thread.getAnimation()->getCurrentExecutionCount();

		if (max_exec != -1 && current_exec >= max_exec) {
			delete *it;
			anim_threads.erase(anim_threads.begin() + i);
		}
	}

	// iterate through each queued process thread
	for (vector<ProcessThread*>::iterator it = proc_threads.begin(); it != proc_threads.end(); it++) {
		ProcessThread& this_thread = **it;
		updateRate = this_thread.getUpdateRate();
		timeSum = this_thread.getTimeSum();

		if (timeSum >= updateRate || this_thread.checkFirstCall()) {
			this_thread.getProcess()->step();
			this_thread.resetTimeSum();
		}
	}
}
