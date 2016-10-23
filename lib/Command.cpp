#include "Command.h"

String name;
Strip* strips;
std::vector<int> stack;
std::vector<int> (*cmd) (std::vector<int>);

// <<constructor>>
Command::Command(String name, Strip* strips, std::vector<int> (*cmd)(std::vector<int>), std::vector<int> var_stack){
	this->name = name;
	this->strips = strips;
	this->stack = var_stack;
	this->cmd = cmd;
}

// <<destructor>>
Command::~Command(){}

// get name
String Command::getName(){
	return this->name;
}

// execute the command
void Command::execute(){
  this->stack = cmd(this->stack);
}

// get the strips that are going to be used
Strip* Command::getDependencies(){
	return this->strips;
}
