#include "cell.h"


// creating a readline function 
char *cell_read_line(void){
    char *buf; //this will store the input of the shell
    size_t bufsize; //this will store the size of the buffer
    char cwd[BUFSIZ]; //this will store the current working directory

    buf = NULL; 
    
    Getcwd(cwd, sizeof(cwd)); //Calling the Getcwd for current working directory fish in cli.
    p(C"🥷 %s "RST" $>", buf); //the interactive shell you are going to look

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

    //we have to implement REPL : Read, evaluate, print and loop
    while(0xCE77){
        
         // 1) get line
        line = cell_read_line(); //TODO
        p("%s\n", line);
        //pause(); => the pause function pause the program here

        // 2) get token gettoken
        // => lexing -> parsing EVALUATING
        //3) Exec
    }


    return EXIT_SUCCESS;
}