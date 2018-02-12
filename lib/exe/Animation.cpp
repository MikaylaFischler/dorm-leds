#include "Animation.hpp"

// basic initialization
void Animation::init() { this->current_exec = 0; }

// abort the animation
void Animation::abort() { /*thread_handler.kill(thread);*/ }

// get number of strips
int Animation::getNumStrips() const { return this->strips.size(); }

// get specific strip dependencies
vector<int> Animation::getDependencies() const { return this->strips; }

// get max execution count
long int Animation::getMaxExecutions() const { return this->max_exec; }

//get current execution count
long int Animation::getCurrentExecutionCount() const { return this->current_exec; }
