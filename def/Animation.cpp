#include "Animation.hpp"

// <<constructor>>
Animation::Animation () { init(); }

// <<destructor>>
Animation::~Animation () {}

// get name
String Animation::getName () { return this->name; }

// get number of strips
int Animation::getNumStrips () { return this->num_strips; }

// get specific strip dependencies
std::vector<int> Animation::getDependencies () { return this->strips; }

// get update rate
int Animation::getUpdateRate () { return this->updateRate; }
