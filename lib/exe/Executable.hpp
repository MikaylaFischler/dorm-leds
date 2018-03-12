#ifndef EXECUTABLE_HPP_
#define EXECUTABLE_HPP_

#include <Arduino.h>

// #include "../Thread.hpp"
// #include "../ThreadHandler.hpp"

// #include "../../conf/globals.h"

class Executable {
protected:
    String name;
    unsigned long int update_rate;
	unsigned int thread;

	Executable() {}
public:
	virtual ~Executable() {}

    String getName() const;
    unsigned long int getUpdateRate() const;
	// virtual void setThread(unsigned int t);

    virtual void init() = 0;
    virtual void step() = 0;
    virtual void abort() = 0;
};

#endif
