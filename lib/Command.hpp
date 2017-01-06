#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>

#include "Strip.h"
#include "LocalStack.hpp"

class Command {
	String name;
	std::vector<int> strips;
    int exec_count;
	bool no_stack;

	LocalStack& stack;
	LocalStack& (*cmd)(LocalStack&);
	void (*cmd_nostack)();
public:
	Command (String name, int strips[], int num_strips, void (*cmd)());
	Command (String name, int strips[], int num_strips, LocalStack& (*cmd)(LocalStack&), LocalStack& var_stack);
	~Command ();

    void execute ();

    String getName ();
    std::vector<int> getDependencies ();
    void getExecCount ();
};

#endif
