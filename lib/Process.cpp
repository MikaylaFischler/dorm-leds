#include "Process.hpp"

// <<constructor>>
Process::Process() {}

// <<destructor>>
Process::~Process() { clean(); }

// basic initialization
void Process::init() {}

// get name
String Process::getName() { return this->name; }

// get update rate
unsigned long int Process::getUpdateRate() { return this->update_rate; }
