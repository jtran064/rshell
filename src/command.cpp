#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <sys/wait.h>
#include <cstring>
#include <cstdlib>
#include "header/command.h"

Command::Command(char ** cmd){
    args = cmd;
}

bool Command::run(bool b) {
    // bool b should not be false
    if(!b){
        L_(lerror) << "This function shouldn't receive a false boolean!";
        return false;
    }

    // if enter exit
    if(strcmp(args[0], "exit") == 0){
        exit(0);
    }

    pid_t child_pid = fork();
    int status;
    if(child_pid >= 0){
        if(child_pid == 0){ // child process
            if (-1 == execvp( *args, args)){
                // L_(lerror) << "Can't Execute"
                perror("Can't execute");
                exit(1);
            }
        }else{ // parent process
            wait(&status);
            if (WIFEXITED(status)){
                if(!WEXITSTATUS(status)){
                    L_(ldebug) << "Return true: status " << WIFEXITED(status);
                    return true;
                }
            }
            L_(ldebug) << "Return true: status " << WIFEXITED(status);
            return false;
        }
    }else{
        perror("Forking error");
        return false;
    }
    L_(ldebug) << "Return false";
    return false;
}

void Command::print(){
    char ** it = args;
    while (*it != NULL){
        std::cout << *it++ << std::endl;
    }
}

Command::~Command(){
    // std::cout << "Command Destructor Called " << std::endl;
    delete args[30];
}

