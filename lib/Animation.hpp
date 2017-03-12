#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <vector>

#include "Executable.hpp"
#include "strip_ownership.h"
#include "led_color.h"
#include "../util/led.c"
#include "../conf/strips.h"

class Animation : public Executable {
protected:
    int num_strips;
    short int* strips;

    long int max_exec;
    long int current_exec;

	Animation();
public:
	virtual ~Animation();
    virtual void init();
	virtual void step() {};
	virtual void clean() {};

    int getNumStrips();
    short int* getDependencies();

	long int getMaxExecutions();
	long int getCurrentExecutionCount();
};

#endif
