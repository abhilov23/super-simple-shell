#include "cell.h"
#include <stdio.h>


int main(int ac, char **av){
    
    (void)ac;
    int status;
    
    //do this in a loop
    //child process
    if(fork() == 0) 
        //execvp() function is a powerful system call,
        //which allows you to replace the current process with a new process specified by the provided command.
        //for "vector", p for "path"
        //takes an array of arguments and uses PATH to find the executable.
        //char **av = {"ls", "-la", NULL};
        //execvp("ls", av);
        execvp(av[1], av +1);
    
    wait(&status); //this returns the value of the child
    return EXIT_SUCCESS;
}