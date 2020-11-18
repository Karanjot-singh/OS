#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char msg[501];
    fgets(msg, sizeof(msg), stdin);
    int pipe1[2], pipe2[2];
    //pipe1: parent reads from p1 & pipe 2: child reads from p2
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("1Error ");
        return -1;
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("2Error ");
        return -1;
    }

    if (pid == 0)
    {
        //Child process
        close(pipe2[1]);
        close(pipe1[0]);
        char new_msg[501];
        read(pipe2[0], new_msg, 501);
        close(pipe2[0]);
        for (int i = 0; new_msg[i] != '\0'; i++)
        {
            if (new_msg[i] >= 'a' && new_msg[i] <= 'z')
            {
                new_msg[i] = new_msg[i] - 32;
            }
            // new_msg[i] = toupper(new_msg[i]);
        }
        write(pipe1[1], new_msg, sizeof(new_msg));
        close(pipe1[1]);
        exit(0);
    }
    else
    {
        // Parent Process
        char new_msg[501];
        close(pipe2[0]);
        close(pipe1[1]);
        write(pipe2[1], msg, sizeof(msg));
        close(pipe2[1]);
        wait(NULL);
        read(pipe1[0], new_msg, 501);
        printf("%s", new_msg);
        close(pipe1[0]);
    }

    return 0;
}

// if (new_msg[i-1]=='\'&& (new_msg[i] == 'a' || new_msg[i] == 'b' || new_msg[i] == 'n' || new_msg[i] == 'f' || new_msg[i] == 'r' || new_msg[i] == 't' || new_msg[i] == 'v' || new_msg[i] == '\\' || new_msg[i] == '0'))