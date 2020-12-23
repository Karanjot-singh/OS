#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char file_name[50], e, c;
int i, j, ec, fg, ec2;
FILE *fp1, *fp2, *fp, *fp3;

void f_create();
void f_del();
void lock(FILE *fp);
void unlock(FILE *fp);
struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        strcpy(file_name, argv[1]);
        fl.l_type = F_RDLCK;
    }
    else if (argc > 2)
    {
        perror("Too many arguments.\n");
    }
    else
    {
        perror("Argument expected.\n");
    }
    // to read and append the file's contents
    fp1 = fopen(file_name, "r");
    //here lock
    if (fp1 == NULL)
    {
        //to create file if doesn't exist
        // fclose(fp1);
        printf("File %s Created Successfully!\n", argv[1]);
        f_create();
    }

    //Read file if exists
    printf("File %s Opened Successfully!\n", argv[1]);

    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
    fp1 = fopen(file_name, "a+");
    lock(fp1);

    printf("\nS - save D - delete E - exit Q-close without save press enter\n");
    char achar;
    // check();
    while (1)
    {
        scanf(" %c", &achar);
        if (achar == 'Q')
        {
            unlock(fp1);
            fclose(fp1);
            return 0;
        }
        if (achar == 'S')
        {
            achar = '\n';
            printf("\n\t");
            fputc(achar, fp1);
            fclose(fp1);
            printf("File saved Successfuly\n");
            unlock(fp1);
            return 0;
        }
        if (achar == 'D')
        {
            f_del();
        }
        if (achar == 'E')
        {
            unlock(fp1);
            printf("Exiting");

            return 0;
        }
        else
        {
            printf("%c", achar);
            fputc(achar, fp1);
        }
    }
}

void f_create()
{
    printf("\nS - save D - delete E - exit Q-close without save \n");

    fp3 = fopen("temp.txt", "w");
    // lock(fp3);
    while (1)
    {
        c = getchar();
        fputc(c, fp3);

        if (c == 'S')
        {
            fclose(fp3);
            fp3 = fopen("temp.txt", "r");
            fp1 = fopen(file_name, "w");
            while (!feof(fp3))
            {
                c = getc(fp3);
                putc(c, fp1);
            }
            // unlock(fp1);
            fclose(fp1);
            printf("File saved Successfuly\n");

            c = 'E';
        }
        if (c == 'Q')
        {
            fclose(fp3);
            if (remove(file_name) == 0)
            {
                printf("File deleted Successfuly\n");
                return;
            }
            fp3 = fopen(file_name, "w");
            // unlock(fp3);
            fclose(fp3);
            c = 'E';
        }
        else if (c == 'E')
        {
            return;
        }
    }
}
void f_del()
{
    fp1 = fopen(file_name, "r");
    if (fp1 == NULL)
    {
        perror("Error: ");
        return;
    }
    fclose(fp1);
    if (remove(file_name) == 0)
    {
        printf("File deleted Successfuly\n");
        return;
    }
    else
        perror("Error: ");
}
void lock(FILE *fp)
{

    fl.l_type = F_RDLCK;
    int fd = fileno(fp);
    printf("\nWarning! Multiple editors open!\n");

    if (fcntl(fd, F_SETLK, &fl) == -1)
    {
        printf("\nWarning! Multiple editors open!\n");
    }
}
void unlock(FILE *fp)
{
    fl.l_type = F_UNLCK; /* set to unlock same region */

    int fd = fileno(fp);
    if (fcntl(fd, F_SETLK, &fl) == -1)
    {
        printf("File unlocked\n");
    }
}
// void check()
// {
//     fl.l_type == F_UNLCK ? printf("") : printf("Other proc writing");
// }