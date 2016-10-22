#ifndef ThreadHandler_H
#define ThreadHandler_H

#include <Arduino.h>
#include <vector>
#include "Strip.h"

class ThreadHandler {
	// thread structure
	struct Thread {
		unsigned int id;
		Command cmd;
	};

	// variables
	std::vector<Thread> threads;
	short int strip_status**;
	unsigned int elapsed_time;
	unsigned int next_id;
public:
	ThreadHandler();
	~ThreadHandler();
	Thread* listThreads();
	void queueThread(Command);
	void executeTick();
private:
	bool conflicts(Strip*, Strip*);
};

#endif
