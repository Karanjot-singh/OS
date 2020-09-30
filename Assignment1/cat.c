#ifndef _cat
#define _cat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#define len 80
#endif

int main(int argc, char *argv[])
{
    char current_path[len * 3];
    getcwd(current_path, len * 3);
    char ch = '/';
    if (strcmp(argv[1], "") == 0)
    {
        // printf("normal/n");
        char filepath[len * 3] = "";
        strcpy(filepath, current_path);
        strncat(filepath, &ch, 1);
        strcat(filepath, argv[2]);
        FILE *fp;
        char read_line[len];
        fp = fopen(filepath, "r");
        if (fp >= 0)
        {

            while (fscanf(fp, "%[^\n]\n", read_line) != EOF)
                printf("%s\n", read_line);
        }
        else
        {
            perror("Error \n");
        }
        
        fclose(fp);
    }
    else if (strcmp(argv[1], "-l") == 0)
    {
    }
    else
    {
    }

    return 0;
}