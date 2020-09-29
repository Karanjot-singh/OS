#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define len 80
struct command
{
    char cmd[len];
    char flag[len];
    char arg[len];
};


// void cmd_cd(struct command *c);