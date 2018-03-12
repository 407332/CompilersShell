#include <iostream>
#include "SimpleCommand.h"
#include <unistd.h>

using namespace std;

void SimpleCommand::execute() {
    //cout << "FIXME: You should change SimpleCommand::execute()" << std::endl;
    // FIXME: Your code here...
    char cwd[1024];

    if (command == "pwd") {


        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            cout << "Current working dir:" << cwd;
        } else {
            cerr << "Error getting current working directory";
        }


    } else if (command == "ls") {
        const char *homePath = std::getenv("HOME");

        std::cout << homePath << " ";
    } else if (command == "cd"){
        
    }

    cout << "\n";
}
