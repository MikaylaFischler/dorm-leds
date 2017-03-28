#include "Animation.hpp"

// <<constructor>>
Executable::Executable() {}

// <<destructor>>
Executable::~Executable() {}

// get the name of the executable
String Executable::getName() const { return this->name; }

// get the update rate of the executable
unsigned long int Executable::getUpdateRate() const { return this->update_rate; }
