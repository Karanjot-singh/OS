#ifndef _echo
#define _echo

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define len 80
#endif

void echo(char *input)
{
    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] == '\\' && input[i + 1] == '\\')
            printf("\\");
        else if (input[i] == '\\')
            continue;
        else
            printf("%c", input[i]);
    }
}
void echoe(char *input)
{
    // Implemented 3 escape sequences \t, \n ...
    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] == '\\' && input[i + 1] == '\t')
            printf("    ");
        else if (input[i] == '\\' && input[i + 1] == '\n')
            printf("\n");
        else if (input[i] == '\\')
            continue;
        else
            printf("%c", input[i]);
    }
    printf("\n");
}

