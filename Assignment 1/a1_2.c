#include <stdio.h> 
#include <string.h>
#include<ctype.h>
#define MAX_LIMIT 20 

// CHECK SPACE =1

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
    int noSpace=1;
    int active =1;
    display();

    // To get input
    while(active==1){
        char str[MAX_LIMIT];
        char str2[MAX_LIMIT];
        //input code for commands
        printf("terminal> ");
        fgets(str, MAX_LIMIT, stdin);
        strcpy(str2,str);

        //check for spaces
        for (int i = 0; i < MAX_LIMIT; ++i){
            char d = str[i];
            if (isspace(d))
                noSpace=0;
        }
        if(noSpace==1){
            if(strcmp(str2,"exit")==0 )
            break;
        }
        else{
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
        if(strcmp(c.cmd,"exit")==0 )
            break;
    }
 
    return 0; 
} 
