#ifndef _mkdir
#define _mkdir
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif

int main(int argc, char *argv[])
{
    char current_path[len * 3];
    getcwd(current_path, len * 3);
    char *name = argv[2];

    if (strcmp(argv[1], "") == 0)
    {
        if (mkdir(name, 0777) != 0)
            perror("Error ");
    }
    else if (strcmp(argv[1], "-v") == 0)
    {
        if (mkdir(name, 0777) != 0)
            perror("Error ");
        else
        {
            printf("mkdir: created directory '%s'\n", name);
        }
    }
    else if (strcmp(argv[1], "-m") == 0)
    {
        printf("Enter file mode \n");
        int mod;
        scanf("%d", &mod);
        if (mkdir(name, mod) != 0)
            perror("Error ");
        else
        {
            printf("mkdir: created directory '%s'\n ", name);
        }
    }
    else
    {
        printf("Enter valid commmand!\n Try command --help\n");
    }
    return 0;
}