#ifndef ThreadHandler_H
#define ThreadHandler_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"
#include "Command.h"
#include "Thread.h"

class ThreadHandler {
	int strip_status[5][2] = { { WINDOW1, STRIP_OFF },
													 	 { WINDOW2, STRIP_OFF },
													 	 { WINDOW3, STRIP_OFF },
													   { DESK1, STRIP_OFF },
													   { DESK2, STRIP_OFF }
												   };
	std::vector<Thread> threads;
	unsigned int elapsed_time;
	unsigned int next_id;
public:
	ThreadHandler();
	~ThreadHandler();
	std::vector<Thread> listThreads();
	void queue(Command* cmd, unsigned long int dU);
	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();
private:
	void setStripsInUse(std::vector<int> str);
	void dequeueConflicts(Command*& cmd);
	bool conflicts(std::vector<int> str);
	bool conflictsWith(std::vector<int> str1, std::vector<int> str2);
};

#endif
