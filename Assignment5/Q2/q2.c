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

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        strcpy(file_name, argv[1]);
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
    if (fp1 == NULL)
    {
        //to create file if doesn't exist
        // fclose(fp1);
        printf("File %s Created Successfully!\n", argv[1]);
        f_create();
        while (1)
        {

            c = getchar();
            if (c == 'E')
            {
                return 0;
            }
        }
    }
    //Read file if exists
    printf("File %s Opened Successfully!\n", argv[1]);

    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
    fp1 = fopen(file_name, "a+");
    printf("\nS - save D - delete E - exit Q-close without save \n");
    char achar;
    while (1)
    {
        scanf(" %c", &achar);
        if (achar == 'Q')
        {
            fclose(fp1);
            return 0;
        }
        if (achar == 'S')
        {
            achar = '\n';
            printf("\n\t");
            fputc(achar, fp1);
            fclose(fp1);
            return 0;
        }
        if (achar == 'D')
        {
            f_del();
        }
        if (achar == 'E')
        {
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
            fclose(fp1);
            c = 'E';
        }
        if (c == 'Q' || c == 'E')
        {
            fclose(fp3);
            if (remove(file_name) == 0)
            {
                printf("File deleted Successfuly");
                return;
            }
            fp3 = fopen(file_name, "w");
            fclose(fp3);
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
        printf("File deleted Successfuly");
        return;
    }
    else
        perror("Error: ");
}