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

    unsigned long int updateRate;
    int max_exec;
    int current_exec;

	Animation();

    virtual void init();
public:
	virtual ~Animation();

	virtual void step() {};
    virtual void clean() {};

    String getName();
    int getNumStrips();
    short int* getDependencies();
    unsigned long int getUpdateRate();
};

#endif
