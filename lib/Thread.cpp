#include "Thread.h"

//<<constructor>>
Thread::Thread(unsigned int id, Command* cmd, unsigned long int t){
  this->id = id;
  this->cmd = cmd;
  this->updateRate = t;
  this->timeSum = t;
}

//<<destructor>>
Thread::~Thread(){}

// get this thread ID
unsigned int Thread::getID(){
  return this->id;
}

// get the command that this thread contains
Command* Thread::getCMD(){
  return this->cmd;
}

// get the update rate
unsigned long int Thread::getUpdateRate(){
  return this->updateRate;
}

// get the current time sum
unsigned long int Thread::getTimeSum(){
  return this->timeSum;
}

// add to the time sum
void Thread::addTimeSum(unsigned int dT){
  this->timeSum += dT;
}

// set the time sum back down to zero
void Thread::zeroTimeSum(){
  this->timeSum = 0;
}
