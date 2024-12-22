#include "cell.h"


// creating a readline function 
char *cell_read_line(void){
    char *buf; //this will store the input of the shell
    size_t bufsize; //this will store the size of the buffer
    char cwd[BUFSIZ]; //this will store the current working directory

    buf = NULL; 
    
    Getcwd(cwd, sizeof(cwd)); //Calling the Getcwd for current working directory fish in cli.
    //the interactive shell you are going to look, and it will also display the current working directory using the function defined in utils.c
    p(C"🥷  %s"RST"$>", cwd); 

    if(getline(&buf, &bufsize, stdin) == -1){

        buf = NULL;
        if(feof(stdin)){ //this is reading the input you are going to place in the shell.
           p(RED"[EOF]"RST);
        } //checking for end of line
        else
        {
          p(RED"getline failed"RST);
        }
            
    }

   return buf;  //return the line read from stdin
 
}


int main(int ac, char **av){
    
    char *line;
    printbanner(); //this will print the banner after the launch of the shell
    //we have to implement REPL : Read, evaluate, print and loop
    while(line = cell_read_line()){ //1)getting the line
         //pause(); => the pause function pause the program here

        // 2) get token gettoken
        // => lexing -> parsing EVALUATING
        //3) Exec
    }


    return EXIT_SUCCESS;
}