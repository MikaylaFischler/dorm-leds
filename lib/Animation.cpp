#include "Animation.hpp"

// <<constructor>>
Animation::Animation() {}

// <<destructor>>
Animation::~Animation() { clean(); }

// basic initialization
void Animation::init() { this->current_exec = 0; }

// get name
String Animation::getName() { return this->name; }

// get number of strips
int Animation::getNumStrips() { return this->num_strips; }

// get specific strip dependencies
short int* Animation::getDependencies() { return this->strips; }

// get update rate
unsigned long int Animation::getUpdateRate() { return this->update_rate; }
