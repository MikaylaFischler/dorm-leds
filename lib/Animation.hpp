#ifndef Animation_H
#define Animation_H

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <vector>

#include "strip_ownership.h"
#include "led_color.h"
#include "Command.hpp"

class Animation {
protected:
    String name;
    int num_strips;
    std::vector<int> strips;

    LocalStack& stack;

    int updateRate;
    int max_exec;
    int current_exec;

    Animation();
    ~Animation();

    virtual void init();
public:
    virtual void clean() = 0;
    virtual void step() = 0;

    String getName();
    int getNumStrips();
    std::vector<int> getDependencies();
    int getUpdateRate();
};

#endif
