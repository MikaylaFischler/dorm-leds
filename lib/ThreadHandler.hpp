#ifndef THREADHANDLER_HPP_
#define THREADHANDLER_HPP_

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>

#include "strip_id.h"
#include "Animation.hpp"
#include "Process.hpp"
#include "Thread.hpp"

#include "../util/mem.c"
#include "../util/free_memory.h"

class ThreadHandler {
private:
	std::vector<AnimationThread*> anim_threads;
	std::vector<ProcessThread*> proc_threads;

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

	std::vector<AnimationThread*> listAnimationThreads() const;
	std::vector<ProcessThread*> listProcessThreads() const;

	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();
};

#endif
