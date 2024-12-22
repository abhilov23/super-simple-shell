#include "cell.h"

t_builtin g_builtin[] ={
    {.builtin_name="echo", .foo=cell_echo},
    {.builtin_name="env", .foo=cell_env},
    {.builtin_name="exit", .foo=cell_exit},
    {.builtin_name= NULL}
};


int status = 0;


void	cell_launch(char **args)
{

	// Is fork returning 2 values?
	if (Fork() == CELL_JR)
	{
		// replace the current process image with a new process image
		//v for "vector", p for "path".
		//Takes an array of arguments and uses PATH to find the executable.
		//	char *args[] = {"ls", "-l", "-a", NULL};
		//	execvp("ls", args);
		Execvp(args[0], args);
	}
	else
	{
		//Automatically waits for any child process, 
		//which is often sufficient for beginner-level 
		//shells that only handle one child process at a time.
		// FINE for CELL v°1
		Wait(&status);

		/*
		Waitpid(cell_jr, &status, 0);
		*/
	}
}



//looking for execution? if it is a builtin command, then execute it else
//execute it using fork + execvp + wait function
// Builtin commands are
// 1) -echo
// 2) -env
// 3) -exit

void cell_exec(char **args){

    int i;
    const char *curr;
    i=0;
    while(curr = g_builtin[i].builtin_name){
        if(!strcmp(curr, args[0]))
        {
          status = g_builtin[i].foo(args); //accessing actual function and call
            return;
        }
        ++i;
    }
    cell_launch(args); //fork->exec  
}


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
        cell_exec(args);
        //4) Free
        free(line); //freeing the memory allocated to the line
        free(args); //freeing the memory allocated to args after using it in the loop.

    }


    return EXIT_SUCCESS;
}