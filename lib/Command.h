#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"

class Command {
	String name;
	Strip* strips;
	std::vector<int> stack;
	std::vector<int> (*cmd) (std::vector<int>);
public:
	Command(String name, Strip* strips, std::vector<int> (*cmd)(std::vector<int>), std::vector<int> var_stack);
	~Command();
	String getName();
	void execute();
	Strip* getDependencies();
};

#endif
