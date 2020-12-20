#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

char file_name[50], e, c;
int i, j, ec, fg, ec2;
FILE *fp1, *fp2, *fp, *fp3;

void f_create();
void f_del();

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        strcpy(file_name, argv[1]);
    }
    else
    {
        strcpy(file_name, "a.txt");
    }

    fp1 = fopen(file_name, "a+");
    if (fp1 == NULL)
    {
        f_create();
        fclose(fp1);
        return 0;
    }
    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
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
    return 0;
}
