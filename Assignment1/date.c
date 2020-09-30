#ifndef _date
#define _date
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define len 80
#endif

int main(int argc, char *argv[])
{
    char buff[len * 3];
    char *name = argv[2];

    if (strcmp(argv[1], "") == 0)
    {
        time_t time_now = time(&time_now);

        if (time_now == -1)
        {
            perror("Error ");
        }

        struct tm *timeInstance = localtime(&time_now);

        if (timeInstance == NULL)
        {

            perror("Error ");
        }

        strftime(buff, 3 * len, "%A, %d %B %Y %H:%M:%S %p %Z", timeInstance);
        puts(buff);
    }
    else if (strcmp(argv[1], "-u") == 0)
    {
        time_t time_now = time(&time_now);

        if (time_now == -1)
        {
            perror("Error ");
        }

        struct tm *timeInstance = gmtime(&time_now);

        if (timeInstance == NULL)
        {
            perror("Error ");
        }
        strftime(buff, 3 * len, "%A %d %B %Y %H:%M:%S %p UTC", timeInstance);
        puts(buff);
    }
    else if (strcmp(argv[1], "-R") == 0)
    {
        time_t time_now = time(&time_now);

        if (time_now == -1)
        {
            perror("Error ");
        }
        struct tm *timeInstance = localtime(&time_now);

        if (timeInstance == NULL)
        {

            perror("Error ");
        }

        strftime(buff, 3 * len, "%a, %d %b %Y %H:%M:%S %z", timeInstance);
        puts(buff);
    }
    else
    {
        printf("Enter valid commmand!\n Try command --help\n");
    }
    return 0;
}