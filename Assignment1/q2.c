#ifndef _q2
#define _q2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
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

int call_process(char *file, char **input)
{
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0)
    {
        printf("f");
        perror("Error ");
        return -1;
    }

    else if (pid == 0)
    {
        //child process
        if (execvp(file, input) < 0)
        {
            perror("Exec failed\n");
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
int main()
{

    char history[10 * len] = "";
    display();

    while (active >= 1)
    {
        char command_temp[len][len];
        char str[3 * len];
        char buff[len];
        printf("%s ", getcwd(buff, len));
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
                perror("Invalid input\n try --help ");
                continue;
            }
        }
        // <history>
        else if (strcmp(c.cmd, "history") == 0)
        {
            if (strcmp(c.flag, "") == 0)
            {
                printf("%s\n", history);
            }
            
            else if (strcmp(c.flag, "-c") == 0)
            {
                strcpy(history, "");
            }
            //
            else if (strcmp(c.flag, "-w") == 0)
            {
                FILE *fp = fopen("/home/karan/Desktop/sem/OS/Assignment1/files/history.txt", "w");
                if (fp == NULL)
                {
                    perror("Error ");
                    continue;
                }
                fprintf(fp, "%s\n", history);
                fclose(fp);
            }
        }
        else if (strcmp(c.cmd, "pwd") == 0)
        {
            if (strcmp(c.arg, "") == 0 && strcmp(c.flag, "") == 0)
            {
                char buffi[len];
                printf("%s \n", getcwd(buffi, len));
            }
            else if (strcmp(c.flag, "") == 0)
            {
                char buffi[len];
                printf("%s \n", getcwd(buffi, len));
            }
            else if (strcmp(c.flag, "--help") == 0)
            {
                printf("\nhelp\n");
            }
            else
            {
                printf("Enter valid commmand!\n Try command --help\n");
            }
        }

        //<cd>
        else if (strcmp(c.cmd, "cd") == 0)
        { //cd implementation
            if (strcmp(c.arg, "") == 0 && strcmp(c.flag, "") == 0)
            {
                printf("cd error");
                perror("Error ");
                continue;
            }
            else if (strcmp(c.flag, "") == 0)
            { //default cd
                if (chdir(c.arg) != 0)
                {
                    perror("cd failed ");
                    continue;
                }
            }
        }
        else if (strcmp(c.cmd, "ls") == 0)
        {
            char *file = "/home/karan/Desktop/sem/OS/Assignment1/ls";
            char *input[3]; //goes to argv
            input[0] = c.cmd;
            input[1] = c.flag;
            input[2] = NULL;
            call_process(file, input);
        }
        else if (strcmp(c.cmd, "cat") == 0)
        {
            char *file = "/home/karan/Desktop/sem/OS/Assignment1/cat";
            char *input[4]; //goes to argv
            input[0] = "cat";
            input[1] = c.flag;
            input[2] = c.arg;
            input[3] = NULL;

            call_process(file, input);
        }
        else if (strcmp(c.cmd, "date") == 0)
        {
            char *file = "/home/karan/Desktop/sem/OS/Assignment1/date";
            char *input[3]; //goes to argv
            input[0] = "date";
            input[1] = c.flag;
            input[2] = NULL;

            call_process(file, input);
        }
        else if (strcmp(c.cmd, "rm") == 0)
        {
            char *file = "/home/karan/Desktop/sem/OS/Assignment1/rm";
            char *input[4]; //goes to argv
            input[0] = "rm";
            input[1] = c.flag;
            input[2] = c.arg;
            input[3] = NULL;

            call_process(file, input);
        }
        else if (strcmp(c.cmd, "mkdir") == 0)
        {
            char *file = "/home/karan/Desktop/sem/OS/Assignment1/mkdir";
            char *input[4]; //goes to argv
            input[0] = "mkdir";
            input[1] = c.flag;
            input[2] = c.arg;
            input[3] = NULL;

            call_process(file, input);
        }
        else if (strcmp(c.cmd, "--help") == 0)
        {
            char *filepath = "/home/karan/Desktop/sem/OS/Assignment1/files/readme.txt";
            FILE *fp;
            char read_line[3 * len];
            fp = fopen(filepath, "r");
            if (fp >= 0)
            {

                while (fscanf(fp, "%[^\n]\n", read_line) != EOF)
                    printf("%s\n\n", read_line);
            }
            else
            {
                perror("Error \n");
            }

            fclose(fp);
        }
        else
        {
            printf("Enter valid commmand!\n Try command --help\n");
        }
    }

    return 0;
}
