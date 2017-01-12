#ifndef ThreadHandler_H
#define ThreadHandler_H

#include <StandardCplusplus.h>
#include <vector>

#include "strip_id.h"
#include "Animation.hpp"
#include "Thread.hpp"

class ThreadHandler {
private:
	std::vector<AnimationThread*> threads;
	std::vector<ProcessThread*> threads;

	unsigned int elapsed_time;
	unsigned int next_id;

	// for animation conflicts
	void dequeueConflicts(Animation* anim);
	bool conflictsWith(short int* str1, int length1, short int* str2, int length2);
public:
	ThreadHandler();
	~ThreadHandler();

	void queue(Animation* anim);
	void queue(Process* proc);

	std::vector<Thread*> listThreads();
	std::vector<AnimationThread*> listAnimationThreads();
	std::vector<ProcessThread*> listProcessThreads();
	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();
};

#endif
