#ifndef ThreadHandler_H
#define ThreadHandler_H

#include <StandardCplusplus.h>
#include <vector>

#include "strip_id.h"
#include "Animation.hpp"
#include "Thread.hpp"

class ThreadHandler {
private:
	int strip_status[5][2] = {	{ WINDOW1, STRIP_OFF },
							 	{ WINDOW2, STRIP_OFF },
							 	{ WINDOW3, STRIP_OFF },
							    { DESK1, STRIP_OFF },
							    { DESK2, STRIP_OFF } };
	std::vector<Thread*> threads;
	unsigned int elapsed_time;
	unsigned int next_id;

	void dequeueConflicts(Animation& anim);
	void setStripsInUse(Animation& anim);
	bool conflictsWith(int* str1, int length1, int* str2, int length2);
public:
	ThreadHandler();
	~ThreadHandler();
	std::vector<Thread*> listThreads();
	void queue(Animation& anim);
	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();
};

#endif
