#include "ThreadHandler.h"

// data
std::vector<Thread*> threads;

unsigned int elapsed_time = 0;
unsigned int next_id = 1;

//<<constructor>>
ThreadHandler::ThreadHandler(){}

//<<destructor>>
ThreadHandler::~ThreadHandler(){}

// get the list of queued threads
std::vector<Thread*> ThreadHandler::listThreads(){
	return threads;
}

// queue a command
void ThreadHandler::queue(Command* cmd, unsigned long int dU){
	dequeueConflicts(cmd);

	// queue this command as a new thread (set current time as the update rate so it initially sets on start)
	Thread* t = new Thread(next_id, cmd, dU);

	next_id++;

	threads.push_back(t);
	setStripsInUse(cmd->getDependencies());

	Serial.println("ThreadHandler.cpp:32>> New Thread Queued");
}

// update the time sums for each thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT){
	// iterate through each queued thread
	for(std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++){
		Thread* this_thread = *it;
		this_thread->addTimeSum(dT);
	}
}

// execute a tick of the handler
void ThreadHandler::executeTick(){
	// iterate through each queued thread
	for(std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++){
		Thread* this_thread = *it;
		unsigned long int updateRate = this_thread->getUpdateRate();
		unsigned long int timeSum = this_thread->getTimeSum();

		if(timeSum >= updateRate){
			this_thread->getCMD()->execute();
			this_thread->zeroTimeSum();
		}
	}
}

// update the list of strips in use
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
void ThreadHandler::setStripsInUse(std::vector<int> str){
	for(int i = 0; i < str.size(); i++){
		for(int y = 0; y < 5; y++){
			if(str.at(i) == this->strip_status[y][0]){
				this->strip_status[y][1] = STRIP_ON;
			}
		}
	}
}

// dequeue any conflicts (recursive)
void ThreadHandler::dequeueConflicts(Command*& cmd){
	int i = 0;
	for(std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); it++, i++){
		Thread* this_thread = *it;

		if(conflictsWith(cmd->getDependencies(), this_thread->getCMD()->getDependencies())){
			threads.erase(threads.begin() + i);
			Serial.println("ThreadHandler.cpp:94>> Conflicting Function De-Queued");
			dequeueConflicts(cmd);
			break;
		}
	}
}

// check if the inputed list conflicts with any of the strips in use
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
bool ThreadHandler::conflicts(std::vector<int> str){
	for(int a = 0; a < str.size(); a++){
		for(int b = 0; b < 5; b++){
			if(str.at(a) == strip_status[b][0] && strip_status[b][1] == STRIP_ON){
				return true;
			}
		}
	}

	return false;
}

// check if the inputed list conflicts another inputed list
// the multiple loops shouldn't have much overhead since it is not possible for either will be larger than 5 elements
bool ThreadHandler::conflictsWith(std::vector<int> str1, std::vector<int> str2){
	for(int a = 0; a < str1.size(); a++){
		for(int b = 0; b < str2.size(); b++){
			if(str1.at(a) == str2.at(b)){
				return true;
			}
		}
	}

	return false;
}
