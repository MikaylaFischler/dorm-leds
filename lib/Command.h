#ifndef Command_H
#define Command_H

#include <Arduino.h>
#include "Strip.h"

class Command {
	struct var {
		String name;
		int value;
	};

	String name;
	Strip* strips;
	std::vector<var> stack;
	void (*cmd) (std::vector<var>);
public:
	Command(String, Strip*, void (*cmd)(std::vector<var>), std::vector<var>);
	~Command();
	String getName();
	void execute(std::vector<var>);
	Strip* getDependencies();
};

#endif
