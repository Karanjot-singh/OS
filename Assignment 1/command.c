#include <stdio.h>
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