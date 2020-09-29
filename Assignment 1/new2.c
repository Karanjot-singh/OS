#include <stdio.h> 
#include <string.h>
#include<ctype.h>
#include <unistd.h>
#define len 80 

//cd pl 
struct command{
    char cmd[len];
    char flag[len];            
    char arg[len];
};

void display(){
    printf("--- Terminal ---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n*All commands end in <space>*\n" );

}

/*
cd l p 
echo Options:
      -n    do not append a newline
      -e    enable interpretation of the following backslash escapes
history -c , -d [offet], -w



*/

int main() 
{   
    struct command c;
    int active =1;
    char buff[len];

    display();

    // To get input
    while(active==1){
        char str[len];
        char str2[len];
        //input code for commands
        printf("terminal> ");
        fgets(str,len, stdin);
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
                printf("%s\n", getcwd(buff,len)); 
            }
        }

    }
 
    return 0; 
} 
