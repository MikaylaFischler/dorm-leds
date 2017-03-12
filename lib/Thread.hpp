#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>

#include "Animation.hpp"

class Thread {
protected:
	unsigned int id;
	unsigned long int updateRate;
	unsigned long int timeSum;
	bool firstCall;

	Thread();
public:
	virtual ~Thread() {}

	unsigned int getID();
	unsigned long int getUpdateRate();
	unsigned long int getTimeSum();
	void addTimeSum(unsigned int dT);
	void zeroTimeSum();
	bool checkFirstCall();
};

class AnimationThread : public Thread {
private:
	Animation* animation;
public:
	AnimationThread(unsigned int id, Animation* anim);
	~AnimationThread();

	Animation* getAnimation();
};

class ProcessThread : public Thread {
private:
	Process* process;
public:
	ProcessThread(unsigned int id, Process* proc);
	~ProcessThread();

	Process* getProcess();
};

#endif
