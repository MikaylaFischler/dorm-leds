#ifndef Animation_H
#define Animation_H

#include <StandardCplusplus.h>
#include <vector>

#include "../conf/strip_ownership.h"
#include "../lib/Command.hpp"

class Animation {
protected:
    String name;
    int num_strips;
    std::vector<int> strips;

    Command& command;
    LocalStack& stack;

    int updateRate;
    int max_exec;
    int current_exec;

    Animation();
    ~Animation();

    virtual void main() = 0;
    virtual void init();
public:
    virtual void clean() = 0;

    String getName();
    int getNumStrips();
    std::vector<int> getDependencies();
    int getUpdateRate();

    virtual Command& getCommand();
};

#endif
