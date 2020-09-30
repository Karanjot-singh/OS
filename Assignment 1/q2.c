#ifndef _q2
#define _q2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <sys/types.h>
#include "cm.c"
#include "echo.c"
#define len 80
#endif

void echoe(char *input);
void echo(char *input);
void display();
void trim_n(char *input);
int active = 1;

int call_process(char *file, char **input1)
{   const char** input;
    strcpy(input, input1);
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0)
    {
        perror("Error ");
        return -1;
    }

    else if (pid == 0)
    {
        //child process
        if (execvp(file, input) < 0)
        {
            printf("*** ERROR: exec failed\n");
            exit(1);
        }
        exit(0);
    }
    else
    {
        //parent process
        pid_t parent_id = waitpid(pid, &status, 0);
    }

    return 0;
}
void prevent_error(int n){
    //outside proccess return exit code to continue while loop
    if (n<0)
    active==2;

}

int main()
{

    char history[10 * len] = "";
    display();

    while (active >= 1)
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
        else if (strcmp(c.cmd, "ls") == 0)
        {
            char *file = "";
            char *argv[4];
            argv[0] = c.cmd;
            argv[1] = c.flag;
            argv[2] = c.arg;
            argv[3]=NULL;
            call_process(file,&argv);
        }
        else if (strcmp(c.cmd, "cat") == 0)
        {
        }
        else if (strcmp(c.cmd, "date") == 0)
        {
        }
        else if (strcmp(c.cmd, "rm") == 0)
        {
        }
        else if (strcmp(c.cmd, "mkdir") == 0)
        {
        }
        else
        {
            printf("Enter valid commmand!\n");
        }
    }

    return 0;
}
