#ifndef _cat
#define _cat
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif


int main(int argc, char * argv[]) { 
    char current_path[128]; 
    getcwd(current_path, 128);

    if(argc == 1){ 
        // numbe rof args supplied
    } 
    else { 
        if(strcmp(argv[1], "") == 0) { 
            printf("normal/n");
        } 
        else if(strcmp(argv[1], "-l") == 0) { 

        } 
        else { 
        } 
    } 
    printf("\n"); 
    return 0; 
} 