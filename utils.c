#include "cell.h"


/**
 * Getcwd - Gets current working directory with error handling
 * @buf: Buffer to store path
 * @size: Size of buffer
 * Return: Pointer to buf on success, NULL on failure
 * Corner cases:
 * - NULL buffer with zero size: allocates buffer
 * - Buffer too small: prints error
 * - Permission denied: prints error
 */
void Getcwd(char *buf, size_t size){
    if(!NULL == getcwd(buf, size)){ //this will get the current working directory
        perror(RED"getcwd failed"RST);
    }
}

pid_t	Fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(RED"Fork failed"RST);
		exit(EX_OSERR);
	}
	return (pid);
}

void	Execvp(const char *file, char *const argv[])
{
	if (!file || !argv)
	{
		fprintf(stderr, RED"Execvp: invalid arguments\n"RST);
		exit(EXIT_FAILURE);
	}
	if (execvp(file, argv) == -1)
	{
		perror(RED"💥CELL_Jr failed💥"RST);
		exit(EX_UNAVAILABLE);
	}
}

pid_t	Wait(int *status)
{
	pid_t	result;

	if (!status)
	{
		fprintf(stderr, RED"Wait: status argument required\n"RST);
		return (-1);
	}
	result = wait(status);
	if (result == -1)
		perror(RED"Wait failed"RST);
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status); 
	return (result);
}


/**
 * Malloc - Allocates memory with error handling
 * @size: Number of bytes to allocate
 * Return: Pointer to allocated memory
 * Corner cases:
 * - Zero size: returns NULL
 * - Allocation failure: prints error and exits
 */
void *Malloc(size_t size){
    void *ptr;
    if(size == 0){
        return (NULL);
    }
    ptr = malloc(size);
    if(!ptr){
        perror(RED"malloc failed"RST);
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

/**
 * Realloc - Reallocates memory with error handling
 * @ptr: Pointer to previously allocated memory
 * @size: New size in bytes
 * Return: Pointer to reallocated memory
 * Corner cases:
 * - NULL ptr: acts as malloc
 * - Zero size: acts as free
 * - Allocation failure: prints error and exits
 */
void	*Realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = realloc(ptr, size);
	if (!new_ptr && size != 0)
	{
		perror(RED"Realloc failed"RST);
		exit(EXIT_FAILURE);
	}
	return (new_ptr);
}

void dbzSpinnerLoading() 
{
    const char *charging[] = {
        "[            ]",
        "[=           ]",
        "[==          ]",
        "[===         ]",
        "[====        ]",
        "[=====       ]",
        "[======      ]",
        "[=======     ]",
        "[========    ]",
        "[=========   ]",
        "[==========  ]",
        "[=========== ]",
        "[===========💥]",
        "👋 Bye👋 Bye👋 Bye!",
    };
    const int frames = sizeof(charging) / sizeof(charging[0]);

	p(RED"Shutting down...\n"RST);

    // Loop through the "charging" animation for 3 seconds
    for (int i = 0; i < frames; i++) {
        p("\r" Y "%s" RST, charging[i]);
        fflush(stdout);  // Force update the console
        usleep(421337);  
    }
	p(C"\n✅ EXIT ✅\n"RST);
	//exit(EX_OK);
}





void printbanner(void){ 
   p(G" ██████╗███████╗██╗     ██╗         ██╗   ██╗  ██╗\n"
      "██╔════╝██╔════╝██║     ██║         ██║   ██║ ███║\n"
      "██║     █████╗  ██║     ██║         ██║   ██║ ╚██║\n"
      "██║     ██╔══╝  ██║     ██║         ╚██╗ ██╔╝  ██║\n"
      "╚██████╗███████╗███████╗███████╗     ╚████╔╝██╗██║\n"
      " ╚═════╝╚══════╝╚══════╝╚══════╝      ╚═══╝ ╚═╝╚═╝\n"
      "Made with ❤️  by Abhilov                           \n"RST);
       

}