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
	unsigned long int updateRate;
	unsigned long int timeSum;
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
	void queue(Command cmd, unsigned long int dU);
	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();
private:
	bool conflicts(Strip*, Strip*);
};

#endif
