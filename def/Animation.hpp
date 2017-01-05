#ifndef Animation_H
#define Animation_H

#include <StandardCplusplus.h>
#include <vector>

#include "../conf/command_conf.h"
#include "../lib/Command.hpp"

class Animation {
protected:
    String name;
    int num_strips;

	std::vector<int> strips;
    Command* command;

    int updateRate;
    int max_exec;
    int current_exec;
public:
    Animation ();
    ~Animation ();

    virtual void main () = 0;
    virtual void init () = 0;

    virtual getName ();
    virtual getNumStrips ();
	virtual std::vector<int> getDependencies ();
    virtual getUpdateRate ();

    virtual Command* getCommand ();
};

#endif
