#include <stdio.h> 
#include <string.h>
#define MAX_LIMIT 20 


struct command{
    char cmd[MAX_LIMIT];        
    char arg[MAX_LIMIT];
    char flag[MAX_LIMIT];
};

void display(){
    printf("--- Terminal ---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n" );

}

int main() 
{   
    struct command c;
    display();
    while(strcmp(c.cmd,"exit")!=0){
        char str[MAX_LIMIT];
        //input code for commands
        printf("terminal> ");
        fgets(str, MAX_LIMIT, stdin);

        char *token;
        token = strtok(str," " );
        strcpy(c.cmd,token);    
        // printf( "%s\n",cmd);
        token = strtok(NULL," ");

        strcpy(c.arg,token);
        // printf( "%s\n",arg);
        token = strtok(NULL," ");

        while(token!=NULL){ 
        strcpy(c.flag,token);
        // printf( "%s\n",flag);
        token = strtok(NULL," ");
        }
    }
 
    return 0; 
} 
