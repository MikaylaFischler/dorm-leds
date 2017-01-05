#ifndef Command_H
#define Command_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"
#include "LocalStack.h"

class Command {
	String name;
	std::vector<int> strips;
	LocalStack* stack;
	LocalStack* (*cmd)(LocalStack*);
public:
	Command(String name, int strips[], int num_strips, LocalStack* (*cmd)(LocalStack*), LocalStack* var_stack);
	~Command();
	String getName();
	void execute();
	std::vector<int> getDependencies();
	int getFEC();
	void resetFEC();
};

#endif
