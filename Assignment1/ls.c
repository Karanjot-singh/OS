#ifndef _ls
#define _ls
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif

void cmd_ls(){
    DIR* directory;
    struct dirent *files;
    //current directory == .
    directory= opendir(".");
    if(directory==NULL){
        perror("Error");
    }
    while(files = readdir(directory)){
        printf("%s\n",files->d_name);
    }
    closedir(directory);
}

int main(int argc, char * argv[]) { 
    char current_path[128]; 
    getcwd(current_path, 128);

    if(argc == 1){ 
        // numbe rof args supplied
        cmd_ls(); 
    } 
    else { 
        if(strcmp(argv[1], "") == 0) { 
            printf("normal/n");
            cmd_ls(); 
        } 
        else if(strcmp(argv[1], "-l") == 0) { 

        } 
        else { 
        } 
    } 
    printf("\n"); 
    return 0; 
} 