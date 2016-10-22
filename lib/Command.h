#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"

struct var {
	String name;
	int value;
};

class Command {
	String name;
	Strip* strips;
	std::vector<var> stack;
	std::vector<var> (*cmd) (std::vector<var>);
public:
	Command(String name, Strip* strips, std::vector<var> (*cmd)(std::vector<var>), std::vector<var> var_stack);
	~Command();
	String getName();
	void execute();
	Strip* getDependencies();
};

#endif
