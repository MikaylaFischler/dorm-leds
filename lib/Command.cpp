#include "Command.hpp"

// <<constructor>>
Command::Command(String name, int strips[], int num_strips, void (*cmd)()) {
	this->name = name;

	std::vector<int> str;

	for(int i = 0; i < num_strips; i++){
		str.push_back(strips[i]);
	}

	this->strips = str;

	this->cmd_nostack = cmd;
	this->no_stack = true;
}

// <<constructor>>
Command::Command(String name, int strips[], int num_strips, LocalStack& (*cmd)(LocalStack&), LocalStack& var_stack) {
	this->name = name;

	std::vector<int> str;

	for(int i = 0; i < num_strips; i++){
		str.push_back(strips[i]);
	}

	this->strips = str;

	this->stack = var_stack;
	this->cmd = cmd;
	this->no_stack = false;
}

// <<destructor>>
Command::~Command() {}

// execute the command
void Command::execute() {
	if (no_stack) {
		cmd_nostack();
	} else {
		this->stack = cmd(this->stack);
	}

	this->exec_count++;
}

// get the strips that are going to be used
std::vector<int> Command::getDependencies() { return this->strips; }

// get execution count
int Command::getExecCount() { return this->exec_count; }
