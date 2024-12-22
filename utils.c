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



void printbanner(void){ 
p(G" :::===  :::  === :::====  :::===== :::====       :::===  ::: :::=======  :::====  :::      :::=====      :::===  :::  === :::===== :::      :::           :::  === :::"
   " :::     :::  === :::  === :::      :::  ===      :::     ::: ::: === === :::  === :::      :::           :::     :::  === :::      :::      :::           :::  === :::"
   "  =====  ===  === =======  ======   =======        =====  === === === === =======  ===      ======         =====  ======== ======   ===      ===           ===  === ==="
   "     === ===  === ===      ===      === ===           === === ===     === ===      ===      ===               === ===  === ===      ===      ===            ======  ==="
   " ======   ======  ===      ======== ===  ===      ======  === ===     === ===      ======== ========      ======  ===  === ======== ======== ========         ==    ==="
   "\nMade with ❤️ by Abhilov \n"RST);  

}