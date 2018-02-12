#include "Executable.hpp"

// get the name of the executable
String Executable::getName() const { return this->name; }

// get the update rate of the executable
unsigned long int Executable::getUpdateRate() const { return this->update_rate; }

// set the thread that this executable is running under
// void Executable::setThread(unsigned int t) const { thread = t; }
