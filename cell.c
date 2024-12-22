#include "cell.h"

//av
//ls -la file
// tokens--> [ls]
//       -->[-la]
//       -->[file]
char **cell_split_line(char *line){
    char **tokens;
    unsigned int position;
    size_t bufsize;
    bufsize = BUFSIZ;
    tokens = Malloc(bufsize * sizeof *tokens);
    position = 0;
    for(char *token = strtok(line, DEL); token;token = strtok(NULL, DEL))
    {
      tokens[position++] = token;
      if(position >= bufsize){
        bufsize *=2;
        tokens = Realloc(tokens, bufsize * sizeof *tokens);  // reallocating the buffer with new size.
      }
    }
    tokens[position]=NULL; //sentinal value
    return tokens; //return the tokens array
}



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
        
        free(buf);  //freeing the memory allocated to the buffer+++++
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
    char **args; //parameter for storing arguments
    printbanner(); //this will print the banner after the launch of the shell
    //we have to implement REPL : Read, evaluate, print and loop
    while(line = cell_read_line()){ //1)getting the line
         //pause(); => the pause function pause the program here
        // 2) get token gettok
        // av-->[ls]
        //   ==>[-a]
        //   ==>[file]
       args = cell_split_line(line);
       
       for(int i=0; args[i]; ++i)
       {
        p("%s\n", args[i]);
       }
        
        //3) Exec
        
        //4) Free
        free(line); //freeing the memory allocated to the line
        free(args); //freeing the memory allocated to args after using it in the loop.

    }


    return EXIT_SUCCESS;
}