#include "Command.h"

String name;
std::vector<int> strips;
std::vector<Command*> cmds;

int current_command = 0;
std::vector<int> exec_counts;
std::vector<int> exec_desired;

// <<constructor>>
CommandGroup::CommandGroup(String name, std::vector<Command*> cmds, std::vector<int> execution_counts){
	this->name = name;
	this->exec_desired =  execution_counts;

	if(cmds.size() != execution_counts.size()){
		Serial.println("Size of vector<Command*> cmds passed to new CommandGroup(...) does not equal size of vector<int> execution_counts!");
		throw std::out_of_range ("Size of vector<Command*> cmds passed to new CommandGroup(...) does not equal size of vector<int> execution_counts!");
	}

 	std::vector<int> temp (exec_desired.size());
	this->execution_counts = temp;

	// build non-conflicting array of dependencies
	std::vector<int> str;

	for(int i = 0; i < cmds.size(); i++){
		for(int j = 0; j < cmds.at(i).getDependencies().size(); j++){
			std::vector<int> d = cmds.at(i).getDependencies();
			short int found = -1;

			for(int k = 0; k < str.size(); k++){
				if(str.(k) == d.at(k)){
					found = true;
					break;
				}
			}

			if(!found){
				str.push_back(d.at(k))
			}
		}
	}

	this->strips = str;
}

// <<destructor>>
CommandGroup::~CommandGroup(){}

// get name
String CommandGroup::getName(){
	return this->name;
}

// execute the command that is supposed to be executed
void CommandGroup::execute(){
	if(current_command >= cmds.size() && cmds.size() != 0){
		current_command = 0;

		for(int i = 0; i < exec_counts.size(); i++){
			exec_counts.at(i) = 0;
		}

		for(int i = 0; i < cmds.size(); i++){
			cmds.at(i)->resetFEC();
		}

		this->execute();
	}else{
		if(exec_counts.at(current_command) > exec_desired.at(current_command)){
			cmds.at(current_command)->execute();
			exec_counts.at(current_command) = cmds.at(current_command)->getFEC();
		}else{
			current_command++;
		}
	}
}

// get the strips that are going to be used
std::vector<int> CommandGroup::getDependencies(){
	return this->strips;
}
