#ifndef Animation_H
#define Animation_H

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <vector>

#include "strip_ownership.h"
#include "led_color.h"
#include "../util/led.c"

class Animation {
protected:
    String name;
    int num_strips;
    short int* strips;

    LocalStack* stack;

    unsigned long int update_rate;
    long int max_exec;
    long int current_exec;

	Animation();
public:
	virtual ~Animation();
    virtual void init();

	virtual void step() {};
    virtual void clean() {};

    String getName();
    int getNumStrips();
    short int* getDependencies();
    unsigned long int getUpdateRate();
	long int getMaxExecutions();
	long int getCurrentExecutionCount();
};

#endif
