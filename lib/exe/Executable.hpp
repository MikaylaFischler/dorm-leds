#ifndef EXECUTABLE_HPP_
#define EXECUTABLE_HPP_

#include <Arduino.h>

class Executable {
protected:
    String name;
    unsigned long int update_rate;

	Executable() {}
public:
	virtual ~Executable() {}

    String getName() const;
    unsigned long int getUpdateRate() const;

    virtual void init() = 0;
    virtual void step() = 0;
};

#endif
