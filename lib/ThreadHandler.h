#ifndef ThreadHandler_H
#define ThreadHandler_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"
#include "Command.h"

// thread structure
struct Thread {
	unsigned int id;
	Command cmd;
};

class ThreadHandler {
	std::vector<Thread> threads;
	short int** strip_status;
	unsigned int elapsed_time;
	unsigned int next_id;
public:
	ThreadHandler();
	~ThreadHandler();
	std::vector<Thread> listThreads();
	void queueThread(Command cmd, std::vector<int> data);
	void executeTick();
private:
	bool conflicts(Strip*, Strip*);
};

#endif
