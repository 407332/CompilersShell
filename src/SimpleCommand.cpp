#include <iostream>
#include "SimpleCommand.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <cstring>

using namespace std;

void SimpleCommand::execute() {
    //cout << "FIXME: You should change SimpleCommand::execute()" << std::endl;
    // FIXME: Your code here...
    char cwd[1024];


    if (command == "pwd") {

        getcwd(cwd, sizeof(cwd));

        if (cwd != nullptr) {
            cout << "Current working dir:" << cwd;
        } else {
            cerr << "Error getting current working directory";
        }

    } else if (command == "ls") {

        DIR *dir = opendir(".");
        struct dirent *entry = readdir(dir);
        while (entry != nullptr) {
            cout << entry->d_name << "\n";
            entry = readdir(dir);
        }
        closedir(dir);

    } else if (command == "cd") {
        if(arguments.empty()){
            strcpy(cwd, getenv("HOME"));
        }else{
            getcwd(cwd, sizeof(cwd));

            if(arguments[0] == ".."){

                for(int i =1024; i>0; i--){
                    if(cwd[i]=='/'){
                        cwd[i] = '\0';
                        i=0;
                    }
                }

            }else {
                strcat(cwd, "/");
                strcat(cwd,arguments[0].c_str());

            }

        }

        cout << cwd;
        chdir(cwd);
    }

    cout << "\n";
}
