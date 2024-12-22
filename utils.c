#include "cell.h"

//WRAPPERS 
void Getcwd(chat *buf, size_t size){
    if(!NULL == getcwd(buf, size)){
        perror(RED"getcwd failed"RST);
    }
}