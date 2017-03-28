#include "Animation.hpp"

// <<constructor>>
Animation::Animation() {}

// <<destructor>>
Animation::~Animation() { clean(); }

// basic initialization
void Animation::init() { this->current_exec = 0; }

// get number of strips
int Animation::getNumStrips() const { return this->num_strips; }

// get specific strip dependencies
short int* Animation::getDependencies() const { return this->strips; }

// get max execution count
long int Animation::getMaxExecutions() const { return this->max_exec; }

//get current execution count
long int Animation::getCurrentExecutionCount() const { return this->current_exec; }
