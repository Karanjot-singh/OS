#ifndef _rm
#define _rm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif

// full directory

int main(int argc, char *argv[])
{
    char current_path[len * 3];
    getcwd(current_path, len * 3);
    char *name = argv[2];

    if (strcmp(argv[1], "") == 0)
    {
        if (unlink(argv[2]) == 0)
        {
        }
        else
        {
            perror("Error ");
        }
    }
    else if (strcmp(argv[1], "-i") == 0)
    {
        char ch;
        printf("rm: remove regular empty file '%s' y/n ?", argv[2]);
        scanf("%c", &ch);
        if (ch == 'y' || 'Y')
            if (unlink(argv[2]) == 0)
            {
            }
            else
            {
                perror("Error ");
            }
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        if (rmdir(argv[2]) == 0)
        {
        }
        else
        {
            perror("Error ");
        }
    }
    else
    {
        printf("Enter valid commmand!\n Try command --help\n");
    }
    return 0;
}