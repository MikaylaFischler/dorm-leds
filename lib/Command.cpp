#include "Command.h"

// <<constructor>>
Command::Command(String name, int strips[], int num_strips, LocalStack* (*cmd)(LocalStack*), LocalStack* var_stack){
	this->name = name;

	std::vector<int> str;

	for(int i = 0; i < num_strips; i++){
		str.push_back(strips[i]);
	}

	this->strips = str;

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
std::vector<int> Command::getDependencies(){
	return this->strips;
}

// get count of full executions
int Command::getFEC(){
	return this->stack->get(0);
}

// reset count of full executions
void Command::resetFEC(){
	this->stack->update(0, 0);
}
