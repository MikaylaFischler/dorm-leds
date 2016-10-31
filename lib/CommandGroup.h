#ifndef CommandGroup_H
#define CommandGroup_H

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>
#include "Strip.h"
#include "Command.h"

class CommandGroup {
	String name;
	std::vector<int> strips;
	std::vector<Command*> cmds;
	int current_command = 0;
	std::vector<int> exec_counts;
	std::vector<int> exec_desired;
public:
	CommandGroup(String name);
	CommandGroup(String name, std::vector<Command*> cmds, std::vector<int> execution_counts);
	~CommandGroup();
	String getName();
	void addCommand(Command cmd, int execution_count);
	void execute();
	std::vector<int> getDependencies();
};

#endif
