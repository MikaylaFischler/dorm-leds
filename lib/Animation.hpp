#ifndef Animation_H
#define Animation_H

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <vector>

#include "strip_ownership.h"
#include "led_color.h"

class Animation {
protected:
    String name;
    int num_strips;
    int* strips;

    LocalStack& stack;

    unsigned long int updateRate;
    int max_exec;
    int current_exec;

    virtual void init();
    virtual void clean() {};
public:
	Animation();
	~Animation();

	virtual void step() {};

    String getName();
    int getNumStrips();
    int* getDependencies();
    int getUpdateRate();
};

#endif
