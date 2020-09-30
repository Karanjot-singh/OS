#ifndef _ls
#define _ls
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#define len 80
#endif

static int comp_string(const void *str1, const void *str2)
{
    return strcmp(*(const char **)str1, *(const char **)str2);
}
void cmd_ls(char *path, int fl)
{
    DIR *directory;
    struct dirent *files;
    char **sort_arr;
    int i = 0;
    //current directory == .
    directory = opendir(path);
    // printf("in ls func\n");
    if (directory == NULL)
    {
        printf("dir null");
        perror("Error");
    }
    if (fl == 1) // ls -a
    {
        while (files = readdir(directory))
        {
            printf("%s\n", files->d_name);
        }
    }
    else if (fl == 0) // ls -U
    {
        while (files = readdir(directory))
        {
            char *fname = files->d_name;
            if (strcmp(fname, ".") == 0 || strcmp(fname, "..") == 0)
            {
            }
            else
                printf("%s\n", files->d_name);
        }
    }
    else if (fl == 2) // ls
    {
        printf("hello\n");
        while (files = readdir(directory))
        {
            char *fname = files->d_name;
            if (strcmp(fname, ".") == 0 || strcmp(fname, "..") == 0)
            {
            }
            else
            {
                // strcpy(sort_arr[i],fname);
                printf("%s", sort_arr[i]);
                i++;
            }
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[])
{
    char current_path[2 * len];
    getcwd(current_path, 2 * len);
    if (strcmp(argv[1], "-U") == 0)
    {
        // printf("normal\n");
        cmd_ls(current_path, 1);
    }
    else if (strcmp(argv[1], "-A") == 0)
    {
        cmd_ls(current_path, 0);
    }
    else if (strcmp(argv[1], "") == 0)
    {
        cmd_ls(current_path, 0);
    }
    else
    {
        printf("Enter valid commmand!\n Try command --help\n");
    }
    return 0;
}