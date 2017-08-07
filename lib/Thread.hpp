#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>

#include "Animation.hpp"

class Thread {
private:
	unsigned int id;
	unsigned long int timeSum;
	bool firstCall;
protected:
	unsigned long int updateRate;

	Thread(unsigned int _id) : id(_id), timeSum(0), firstCall(true) {}
public:
	virtual ~Thread() {}

	void addTime(unsigned int dT);
	void resetTimeSum();

	bool checkFirstCall();

	unsigned int getID() const;
	unsigned long int getUpdateRate() const;
	unsigned long int getTimeSum() const;
};

class AnimationThread : public Thread {
private:
	Animation* animation;
public:
	AnimationThread(unsigned int id, Animation* anim);
	~AnimationThread();

	Animation* getAnimation() const;
};

class ProcessThread : public Thread {
private:
	Process* process;
public:
	ProcessThread(unsigned int id, Process* proc);
	~ProcessThread();

	Process* getProcess() const;
};

#endif
