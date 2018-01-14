#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// #include <FastLED.h>
#include <ArduinoSTL.h>
#include <vector>

#include "Executable.hpp"
#include "../def/led_color.h"
#include "../../util/led.c"

using std::vector;

class Animation : public Executable {
protected:
    vector<int> strips;

    long int max_exec;
    long int current_exec;

	Animation() {}
public:
	virtual ~Animation() {}

    virtual void init();
	virtual void step() {}
	virtual void abort();

    int getNumStrips() const;
    vector<int> getDependencies() const;

	long int getMaxExecutions() const;
	long int getCurrentExecutionCount() const;
};

#endif
