#ifndef Executable_H
#define Executable_H

#include <Arduino.h>
#include "LocalStack.hpp"

class Executable {
protected:
    String name;
    LocalStack* stack;
    unsigned long int update_rate;

	Executable() {}
public:
	virtual ~Executable() {}

    virtual void init() {}
    virtual void clean() {}
    String getName() { return this->name; }
    unsigned long int getUpdateRate() { return this->update_rate; }
};

#endif
