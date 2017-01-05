#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>

#include "Strip.h"
#include "LocalStack.hpp"

class Command : public Executable {
	String name;
	std::vector<int> strips;
    int exec_count;

	LocalStack* stack;
	LocalStack* (*cmd)(LocalStack*);
public:
	Command (String name, int strips[], int num_strips, LocalStack* (*cmd)(LocalStack*), LocalStack* var_stack);
	~Command ();

    void execute ();

    String getName ();
    std::vector<int> getDependencies ();
    void getExecCount ();
};

#endif
