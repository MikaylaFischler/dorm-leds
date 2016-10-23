#include "ThreadHandler.h"

// set up all strips as not in use
short int strip_status[5][2] = { { WINDOW1, false },
										      	     { WINDOW2, false },
											           { WINDOW3, false },
											           { DESK1, false },
											           { DESK2, false }
											         };

// data
std::vector<Thread> threads;

unsigned int elapsed_time = 0;
unsigned int next_id = 1;

//<<constructor>>
ThreadHandler::ThreadHandler(){}

//<<destructor>>
ThreadHandler::~ThreadHandler(){}

// get the list of queued threads
std::vector<Thread> ThreadHandler::listThreads(){
	return threads;
}

// queue a command
void ThreadHandler::queue(Command* cmd, unsigned long int dU){
	int i = 0;
	for(std::vector<Thread>::iterator it = threads.begin(); it != threads.end(); it++, i++){
		Thread this_thread = *it;

		if(conflicts(cmd->getDependencies(), this_thread.getCMD()->getDependencies())){
			// de-queue any conflicting commands
			threads.erase(threads.begin() + i);
		}
	}

	// queue this command as a new thread (set current time as the update rate so it initially sets on start)
	Thread t = Thread(next_id, cmd, dU);

	next_id++;

	threads.push_back(t);
}

// update the time sums for each thread
void ThreadHandler::updateTimeAccumulated(unsigned long int dT){
	// iterate through each queued thread
	for(std::vector<Thread>::iterator it = threads.begin(); it != threads.end(); it++){
		Thread this_thread = *it;
		this_thread.addTimeSum(dT);
	}
}

// execute a tick of the handler
void ThreadHandler::executeTick(){
	// iterate through each queued thread
	for(std::vector<Thread>::iterator it = threads.begin(); it != threads.end(); it++){
		Thread this_thread = *it;
		unsigned long int updateRate = this_thread.getUpdateRate();
		unsigned long int timeSum = this_thread.getTimeSum();

		if(timeSum >= updateRate){
			this_thread.getCMD()->execute();
			this_thread.zeroTimeSum();
		}
	}
}

// check if two list of strips conflict with eachother
// the multiple loops shouldn't have much overhead since it is unlikely either will be larger than 3 elements
bool ThreadHandler::conflicts(Strip* a, Strip* b){
	for(int x = 0; x < (sizeof(a)/sizeof(*a)); x++){
		for(int y = 0; y < (sizeof(b)/sizeof(*b)); y++){
			if(a[x] == b[y]){
				return true;
			}
		}
	}

	return false;
}
