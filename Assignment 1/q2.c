#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
// #include "cm.c"
#include "echo.c"
#define len 80
#ifndef cm
struct command
{
    char cmd[len];
    char flag[len];
    char arg[len];
};
#endif

void echoe(char *input);
void echo(char *input);
void display();
void trim_n(char *input)
{
    size_t size = strlen(input);
    if ((input[size - 1] == '\n') && (size > 0))
        input[size - 1] = '\0';
}

int main()
{
    int active = 1;
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
            else
            {
                perror("Invalid input/n try --help ");
                continue;
            }
        }
        // <history>
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
                if (fp == NULL)
                {
                    perror("Error ");
                    continue;
                }
                fprintf(fp, "%s\n", history);
                fclose(fp);
            }
        }

        //<cd>
        else if (strcmp(c.cmd, "cd") == 0)
        { //cd implementation
            if (strcmp(c.arg, "") == 0 && strcmp(c.flag, "") == 0)
            {
                perror("Error ");
                continue;
            }
            else if (strcmp(c.flag, "") == 0)
            { //default cd
                chdir(c.arg);
                char buff[len];
                printf("%s\n", getcwd(buff, len));
            }
        }
    }
    return 0;
}
