#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>   //including header files    //stdio.h used for input or output operations
#include <string.h>  //used for strcpy function
#include <stdlib.h>  //used for system("clear") function
#include <termios.h> //used for getc function
#include <unistd.h>
int i, j, ec, fg, ec2;
char fn[20], e, c;
FILE *fp1, *fp2, *fp;
void Create();
void Append();
void Delete();
void Display();
void main()
{
    do
    {
        system("clear");
        printf("\n\t\t***** TEXT EDITOR *****");
        printf("\n\n\tMENU:\n\t-----\n ");
        printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ec);
        switch (ec)
        {
        case 1:
            Create();
            break;
        case 2:
            Display();
            break;
        case 3:
            Append();
            break;
        case 4:
            Delete();
            break;
        case 5:
            exit(0);
        }
    } while (1);
}
void Create()
{
    fp1 = fopen("temp.txt", "w");
    printf("\n\tEnter the text and press '.' to save\n\n\t");
    while (1)
    {
        c = getchar();
        fputc(c, fp1);
        if (c == '.')
        {
            fclose(fp1);
            printf("\n\tEnter then new filename: ");
            scanf("%s", fn);
            fp1 = fopen("temp.txt", "r");
            fp2 = fopen(fn, "w");
            while (!feof(fp1))
            {
                c = getc(fp1);
                putc(c, fp2);
            }
            fclose(fp2);
            break;
        }
    }
}
void Display()
{
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if (fp1 == NULL)
    {
        printf("\n\tFile not found!");
        return;
    }
    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
}
void Delete()
{
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if (fp1 == NULL)
    {
        printf("\n\tFile not found!");
        return;
    }
    fclose(fp1);
    if (remove(fn) == 0)
    {
        printf("\n\n\tFile has been deleted successfully!");
        return;
    }
    else
        printf("\n\tError!\n");
}
void Append()
{
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if (fp1 == NULL)
    {
        printf("\n\tFile not found!");
        fclose(fp1);
        return;
    }
    while (!feof(fp1))
    {
        c = getc(fp1);
        printf("%c", c);
    }
    fclose(fp1);
    printf("\n\tType the text and press 'Ctrl+S' to append.\n");
    fp1 = fopen(fn, "a");
    while (1)
    {
        c = getc(fp1);
        if (c == 19)
        {
            fclose(fp1);
            return;
        }
        if (c == 13)
        {
            c = '\n';
            printf("\n\t");
            fputc(c, fp1);
        }
        else
        {
            printf("%c", c);
            fputc(c, fp1);
        }
        fclose(fp1);
    }
}