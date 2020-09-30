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

void cmd_cat(char* path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        perror("Error ");
    }
    while(! feof(fp)){
        char read= fgetc(fp);
        printf("%c",read);
    }
    fclose(fp);
    return;
}

int main(int argc, char *argv[])
{
    char current_path[len*3];
    getcwd(current_path, len*3);

    if (argc == 1)
    {
        // numbe rof args supplied
        printf("so");
    }
    else
    {
        if (strcmp(argv[1], "") == 0)
        {
            // printf("normal/n");
            char filepath[len*3];
            strcpy(filepath,current_path);
            strcat(filepath,argv[2]);
            printf("\n%s",filepath);
            cmd_cat(filepath);
        }
        else if (strcmp(argv[1], "-l") == 0)
        {
        }
        else
        {
        }
    }
    printf("\n");
    return 0;
}