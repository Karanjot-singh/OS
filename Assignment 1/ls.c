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
        return -1;
    }
    while(files = readdir(directory)){
        printf("%s\n",files->d_name);
    }
    closedir(directory);
    return 0;
}

int main(int argc, char * argv[]) { 
    char current_path[128]; 
    getcwd(current_path, 128);

    if(argc == 1){ 
        // ls(current_path, 0); 
    } 
    else { 
        if(strcmp(argv[1], "") == 0) { 
            printf("normal/n");
            cmd_ls(); 
        } else if(strcmp(argv[1], "-r") == 0) { 
            ls_r(current_path); 
        } else { 
            ls(current_path, 1);  // ls -a 
        } 
    } 
    printf("\n"); 
    return 0; 
} 