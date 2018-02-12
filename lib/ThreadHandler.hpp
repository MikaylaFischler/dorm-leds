#ifndef THREADHANDLER_HPP_
#define THREADHANDLER_HPP_

#include <Arduino.h>
#include <ArduinoSTL.h>
#include <vector>

#include "exe/Animation.hpp"
#include "exe/Process.hpp"

#include "Thread.hpp"

#include "../util/free_memory.h"

#include "../conf/globals.h"

using std::vector;

class ThreadHandler {
private:
	vector<AnimationThread*> anim_threads;
	vector<ProcessThread*> proc_threads;

	unsigned int elapsed_time;
	unsigned int next_id;
public:
	ThreadHandler() {}
	~ThreadHandler() {}

	void queue(Animation* anim);
	void queue(Process* proc);
	// void kill(unsigned int id);

	void updateTimeAccumulated(unsigned long int dT);
	void executeTick();

	vector<AnimationThread*> listAnimationThreads() const;
	vector<ProcessThread*> listProcessThreads() const;
};

#endif
