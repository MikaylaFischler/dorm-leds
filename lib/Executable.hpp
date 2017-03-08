#ifndef Executable_H
#define Executable_H

#include <Arduino.h>
#include "LocalStack.hpp"

class Executable {
protected:
    String name;
    LocalStack* stack;
    unsigned long int update_rate;

	Executable();
public:
	virtual ~Executable();

    virtual void init() = 0;
    virtual void step() = 0;
    virtual void clean() = 0;

    String getName();
    unsigned long int getUpdateRate();
};

#endif
