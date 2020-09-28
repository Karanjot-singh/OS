#include <stdio.h> 
#include <string.h>
#include<ctype.h>
#include <unistd.h>
#define MAX_LIMIT 20 


struct command{
    char cmd[MAX_LIMIT];        
    char arg[MAX_LIMIT];
    char flag[MAX_LIMIT];
};

void display(){
    printf("--- Terminal ---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n*All commands end in <space>*\n" );

}

int main() 
{   
    struct command c;
    int active =1;
    char buff[MAX_LIMIT];

    display();

    // To get input
    while(active==1){
        char str[MAX_LIMIT];
        char str2[MAX_LIMIT];
        //input code for commands
        printf("terminal> ");
        fgets(str, MAX_LIMIT, stdin);
        strcpy(str2,str);

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

        //exit
        if(strcmp(c.cmd,"exit")==0 || strcmp(c.cmd,"Exit")==0 )
            break;
        else if(strcmp(c.cmd,"cd")==0){
            if(strcmp(c.arg,"")==0)
                printf("Valid format cd <directory>\n" );
            else if(strcmp(c.flag,"")==0)
            {
                chdir(c.arg);
                printf("%s\n", getcwd(buff,MAX_LIMIT)); 
            }
        }

    }
 
    return 0; 
} 
