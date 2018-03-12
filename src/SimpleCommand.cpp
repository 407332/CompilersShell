#include <iostream>
#include "SimpleCommand.h"
#include "main.cpp"

using namespace std;
void SimpleCommand::execute() {
	//cout << "FIXME: You should change SimpleCommand::execute()" << std::endl;
	// FIXME: Your code here...



	if(command == "cd"){
        const char* homePath = std::getenv("HOME");

        cout << homePath << " ";
	}else if(command == "ls"){

    }
}
