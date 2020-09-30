// pid_t pid;
//     int status;
//     pid = fork();

//     if (pid < 0)
//     {
//         perror("Error ");
//         return -1;
//     }

//     else if (pid == 0)
//     {
//         //child process

//         if (execvp(file, input) < 0)
//         {
//             printf("*** ERROR: exec failed\n");
//             exit(1);
//         }

//         exit(0);
//     }
//     else
//     {
//         //parent process
// 		pid_t parent_id = waitpid(pid, &status, 0);
//     }
    
//     return 0;

//     //

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