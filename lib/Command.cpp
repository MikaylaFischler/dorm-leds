#include "Command.h"

String name;
std::vector<int> strips;
std::vector<int> stack;
std::vector<int> (*cmd) (std::vector<int>);

// <<constructor>>
Command::Command(String name, int strips[], int num_strips, std::vector<int> (*cmd)(std::vector<int>), std::vector<int> var_stack){
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
