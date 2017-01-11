#include "Thread.hpp"

//<<constructor>>
Thread::Thread (unsigned int id, Animation* anim) {
	anim->init();

	this->firstCall = true;
	this->id = id;
	this->animation = anim;
	this->updateRate = anim->getUpdateRate();
	this->timeSum = 0;
}

//<<destructor>>
Thread::~Thread() { delete this->animation; }

// get this thread ID
unsigned int Thread::getID() { return this->id; }

// get the update rate
unsigned long int Thread::getUpdateRate() { return this->updateRate; }

// get the current time sum
unsigned long int Thread::getTimeSum() { return this->timeSum; }

// add to the time sum
void Thread::addTimeSum(unsigned int dT) { this->timeSum += dT; }

// set the time sum back down to zero
void Thread::zeroTimeSum() { this->timeSum = 0; }

// check first call
bool Thread::checkFirstCall() {
	bool temp = this->firstCall;
	this->firstCall = false;
	return temp;
}

// get the command that this thread contains
Animation* Thread::getAnimation() { return animation; }
