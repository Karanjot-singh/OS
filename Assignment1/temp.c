#ifndef _cat
#define _cat
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif

void cmd_cat(char *path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        perror("Error ");
    }
    while (!feof(fp))
    {
        char read = fgetc(fp);
        printf("%c", read);
    }
    fclose(fp);
    return;
}

int main(int argc, char *argv[])
{
    char current_path[len * 3];
    getcwd(current_path, len * 3);

    if (argc == 1)
    {
        // numbe rof args supplied
        printf("so");
    }
    else
    {
        if (strcmp(argv[1], "") == 0)
        {
            // printf( "normal/n" );
            char filepath[len * 3];
            strcpy(filepath, current_path);
            strcat(filepath, argv[2]);
            printf("\n%s", filepath);
            cmd_cat(filepath);
        }
        else if (strcmp(argv[1], "-l") == 0)
        {
        }
        else
        {
            printf("Enter valid commmand!\n Try command --help\n");
        }
    }
    printf("\n");
    return 0;
}
// pid_t pid;
//     int status;
//     pid = fork(  );

//     if ( pid < 0 )
//     {
//         perror( "Error " );
//         return -1;
//     }

//     else if ( pid == 0 )
//     {
//         //child process

//         if ( execvp( fp,input ) < 0 )
//         {
//             printf( "*** ERROR: exec failed\n" );
//             exit( 1 );
//         }

//         exit( 0 );
//     }
//     else
//     {
//         //parent process
// 		pid_t parent_id = waitpid( pid,&status,0 );
//     }

//     return 0;

//

// int call_process( char *fp,char **input1 )
// {   const char** input;
//     strcpy( input,input1 );
//     pid_t pid;
//     int status;
//     pid = fork(  );

//     if ( pid < 0 )
//     {
//         perror( "Error " );
//         return -1;
//     }

//     else if ( pid == 0 )
//     {
//         //child process
//         if ( execvp( fp,input ) < 0 )
//         {
//             printf( "*** ERROR: exec failed\n" );
//             exit( 1 );
//         }
//         exit( 0 );
//     }
//     else
//     {
//         //parent process
//         pid_t parent_id = waitpid( pid,&status,0 );
//     }

//     return 0;
// }