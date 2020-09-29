#include <stdio.h>
#include <string.h>
#define len 80
struct command
{
    char cmd[len];
    char flag[len];
    char arg[len];
};

void display()
{
    printf("> Terminal\n Available commands:\n");
    printf("‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n");
    printf("‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n");
    printf("Format: [cmd] [flag] [args]\n");
}
void trim_n(char *input)
{
    size_t size = strlen(input);
    if ((input[size - 1] == '\n') && (size > 0))
        input[size - 1] = '\0';
}

/*
cd l p 
echo Options:
      -n    do not append a newline
      -e    enable interpretation of the following backslash escapes
history -c , -w

date -R, -u
ls -a ls-h
rm -i -d

*/