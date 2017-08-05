#include "Thread.hpp"

//<<constructor>>
Thread::Thread() : firstCall(true), timeSum(0) {}

// add to the time sum
void Thread::addTime(unsigned int dT) { this->timeSum += dT; }

// set the time sum back down to zero
void Thread::resetTimeSum() { this->timeSum = 0; }

// check first call
bool Thread::checkFirstCall() {
	bool temp = this->firstCall;
	this->firstCall = false;
	return temp;
}

/* ~~~ Get Functions ~~~ */

// get this thread ID
unsigned int Thread::getID() const { return this->id; }

// get the update rate
unsigned long int Thread::getUpdateRate() const { return this->updateRate; }

// get the current time sum
unsigned long int Thread::getTimeSum() const { return this->timeSum; }

/* ~~~ Animation Thread Subclass ~~~ */

//<<constructor>>
AnimationThread::AnimationThread (unsigned int id, Animation* anim) {
	this->id = id;
	this->animation = anim;
	this->updateRate = anim->getUpdateRate();
}

//<<destructor>>
AnimationThread::~AnimationThread() { delete this->animation; }

// get the command that this thread contains
Animation* AnimationThread::getAnimation() const { return animation; }

/* ~~~ Process Thread Subclass ~~~ */

//<<constructor>>
ProcessThread::ProcessThread (unsigned int id, Process* proc) {
	this->id = id;
	this->process = proc;
	this->updateRate = proc->getUpdateRate();
}

//<<destructor>>
ProcessThread::~ProcessThread() { delete this->process; }

// get the command that this thread contains
Process* ProcessThread::getProcess() const { return process; }
