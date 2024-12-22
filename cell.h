#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

 void Getcwd(char *, size_t);

#endif