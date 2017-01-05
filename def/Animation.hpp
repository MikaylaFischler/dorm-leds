#ifndef Animation_H
#define Animation_H

#include <StandardCplusplus.h>
#include <vector>

#include "../conf/command_conf.h"
#include "../lib/Executable.hpp"

class Animation {
protected:
    String name;
    int num_strips;
	std::vector<int> strips;

    int updateRate;
    int max_exec;
    int current_exec;
public:
    Animation ();
    ~Animation ();

    virtual Executable* getExecutable () = 0;
    virtual void main () = 0;
    virtual void init () = 0;

    virtual getName ();
    virtual getNumStrips ();
	virtual std::vector<int> getDependencies ();
    virtual getUpdateRate ();
};

#endif
