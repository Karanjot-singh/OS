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

void cmd_cd(struct command *c)
{
    //cd implementation
    if (strcmp(c->flag, "") == 0)
    { //default cd
        chdir(c->arg);
        char buff[len];
        printf("%s\n", getcwd(buff, len));
    }
}
