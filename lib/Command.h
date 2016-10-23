#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"

class Command {
	String name;
	std::vector<int> strips;
	std::vector<int> stack;
	std::vector<int> (*cmd) (std::vector<int>);
public:
	Command(String name, int *strips, int num_strips,std::vector<int> (*cmd)(std::vector<int>), std::vector<int> var_stack);
	~Command();
	String getName();
	void execute();
	std::vector<int> getDependencies();
};

#endif
