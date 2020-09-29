#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "cd.c"
#define len 80
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
struct command
{
    char cmd[len];
    char flag[len];
    char arg[len];
};

void cmd_cd(struct command *c);

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
}

int main()
{
    int active = 1;
    char buff[len];
    char history[10 * len] = "";
    display();

    while (active == 1)
    {
        char command_temp[len][len];
        char str[3 * len];
        printf("$ ");
        fgets(str, 3 * len, stdin);
        strcat(history, str);
        int j = 0;
        int spaces = 0;
        for (int i = 0; i <= strlen(str); ++i)
        {
            if (str[i] == '\0' || str[i] == ' ')
            {
                command_temp[spaces][j] = '\0';
                j = 0;
                spaces++;
            }
            else
            {
                command_temp[spaces][j] = str[i];
                j++;
            }
        }
        struct command c;
        char test[len];
        trim_n(command_temp[0]);
        trim_n(command_temp[1]);
        trim_n(command_temp[2]);
        strcpy(c.cmd, command_temp[0]);
        strcpy(c.flag, command_temp[1]);
        strcpy(c.arg, command_temp[2]);

        if (strcmp(c.cmd, "exit") == 0)
            break;
        //<echo>
        else if (strcmp(c.cmd, "echo") == 0)
        {
            // echo  txt
            if (strcmp(c.flag, "") == 0)
            {
                echo(c.arg);
                printf("\n");
            }
            // echo -n txt
            else if (strcmp(c.flag, "-n") == 0)
            {
                echo(c.arg);
            }
            //echo -e txt
            else if (strcmp(c.flag, "-e") == 0)
            {
                echoe(c.arg);
            }
            else{

                perror("Invalid input/n try --help ");
                continue;
            }
        }
        else if (strcmp(c.cmd, "history") == 0)
        {
            if (strcmp(c.flag, "") == 0)
            { 
                printf("%s/n", history);
            }
            //
            else if (strcmp(c.flag, "-c") == 0)
            {
                strcpy(history, "");
            }
            //
            else if (strcmp(c.flag, "-w") == 0)
            {
                FILE *fp = fopen("/home/karan/Desktop/sem/OS/Assignment 1/files/history.txt", "w");
                if (fp == NULL){
                    perror("Error ");
                    continue;
                    }
                fprintf(fp, "%s\n", history);
                fclose(fp);
            }
        }

        //<cd>
        else if (strcmp(c.cmd, "cd") == 0)
        {
            //cd implementation

            if (strcmp(c.arg, "") == 0 && strcmp(c.flag, "") == 0){
                perror("Error ");
                continue;
            }

            // else if (strcmp(c.flag, "") == 0)
            // { //default cd
            //     chdir(c.arg);
            //     printf("%s\n", getcwd(buff, len));
            // }
        }
    }
    return 0;
}
