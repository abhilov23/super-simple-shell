#ifndef CELL_H
#define CELL_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sysexits.h>

/*
** Adding ANSI color code for terminal output formatting:
** Y - yellow
** G - green
** C - cyan
** RED - red
** RST - reset to default color
 */
 #define Y "\033[1;33m"
 #define G "\033[0;32m"
 #define C "\033[0;36m"
 #define RED "\033[0;31m"
 #define RST "\033[0m"

 //defining a macro for printf
 #define p(...) printf(__VA_ARGS__)
 #define DEL "\n\t \v\f\r"
 #define CELL_JR 0


 typedef struct s_builtin{
    const char *builtin_name;
    int (*foo) (char **);
 } t_builtin;

 int cell_echo(char **args);  /* Echo command implementation */
 int cell_env(char **args);   /* Environment variables display */
 int cell_exit(char **);

 void Getcwd(char *, size_t); //for executing getcwd() function for current working directory
 void printbanner(void); //for the print banner text
 void	*Malloc(size_t size);  //for Memory allocation 
 void	*Realloc(void *ptr, size_t size); /* Memory reallocation */
 void  dbzSpinnerLoading(); //animated loading spinner
 
 pid_t	Wait(int *status);
 void	Execvp(const char *file, char *const argv[]); /* Execute program */
 pid_t	Fork(void);                   /* Process creation */


#endif