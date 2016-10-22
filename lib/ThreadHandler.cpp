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

// queue a thread
void ThreadHandler::queueThread(Command cmd, std::vector<int> data){
	for(int i = 0; i < threads.size(); i++){
		if(conflicts(cmd.getDependencies(), threads.at(i).cmd.getDependencies())){
			// de-queue any conflicting commands
			threads.erase(i);
		}
	}

	// queue this command as a new thread
	Thread t = {next_id, cmd};

	next_id++;

	threads.push_back(t);
}

// execute a tick of the handler
void ThreadHandler::executeTick(){
	// iterate through each queued thread
	for(std::vector<Thread>::iterator i = threads.begin(); i != threads.end(); ++i){
		threads.at(i).cmd.execute();
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
