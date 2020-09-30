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

// static int myCompare(const void* a, const void* b) 
// { 
  
//     // setting up rules for comparison 
//     return strcmp(*(const char**)a, *(const char**)b); 
// } 
  
// // Function to sort the array 
// void sort(const char* arr[], int n) 
// { 
//     // calling qsort function to sort the array 
//     // with the help of Comparator 
//     qsort(arr, n, sizeof(const char*), myCompare); 
// } 
  
// int main() 
// { 
  
//     // Get the array of names to be sorted 
//     const char* arr[] 
//         = { "geeksforgeeks", "geeksquiz", "clanguage" }; 
  
//     int n = sizeof(arr) / sizeof(arr[0]); 
//     int i; 
  
//     // Print the given names 
//     printf("Given array is\n"); 
//     for (i = 0; i < n; i++) 
//         printf("%d: %s \n", i, arr[i]); 
  
//     // Sort the given names 
//     sort(arr, n); 
void cmd_ls(char *path, int fl)
{
    DIR *directory;
    struct dirent *files;
    //current directory == .
    directory = opendir(path);
    // printf("in ls func\n");
    if (directory == NULL)
    {
        printf("dir null");
        perror("Error");
    }
    while (files = readdir(directory))
    {
        if (fl == 1) // ls -a
            printf("%s\n", files->d_name);
        else if (fl == 0) // ls -U
        {
            char *fname = files->d_name;
            if (strcmp(fname, ".")==0 || strcmp(fname, "..")==0)
            {
                continue;
            }
            else
                printf("%s\n", files->d_name);
        }
    }
    closedir(directory);
}

int main(int argc, char *argv[])
{
    char current_path[2 * len];
    getcwd(current_path, 2 * len);
    // printf("dir: %s",current_path);
    if (argc == 1)
    {
        // numbe rof args supplied
        printf("this");
        cmd_ls(current_path, 0);
    }
    else
    {
        if (strcmp(argv[1], "-U") == 0)
        {
            // printf("normal\n");
            cmd_ls(current_path, 0);
        }
        else if (strcmp(argv[1], "-a") == 0)
        {
            cmd_ls(current_path, 1);
        }
        else if (strcmp(argv[1], "") == 0)
        {
            cmd_ls(current_path, 0);
        }
        else
        {
        }
    }
    return 0;
}