#include <stdio.h> 
#include <string.h>
#define MAX_LIMIT 20 

//input code for commands
int main() 
{ 
    char str[MAX_LIMIT];
    char cmd[MAX_LIMIT];
    char arg[MAX_LIMIT];
    char flag[MAX_LIMIT];

    fgets(str, MAX_LIMIT, stdin);
    printf("%s", str);
    char *token;
    int ct=0;
    token = strtok(str," " );
    strcpy(cmd,token);    
    printf( "%s\n",token);
    token = strtok(NULL," ");

    strcpy(arg,token);
    printf( "%s\n",token);
    token = strtok(NULL," ");

    while(token!=NULL){ 
    strcpy(flag,token);
    printf( "%s\n",token);
    token = strtok(NULL," ");
    }
 
    return 0; 
} 
