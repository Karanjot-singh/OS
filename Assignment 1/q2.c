#include <stdio.h> 
#include <string.h>
#include<ctype.h>
#include <unistd.h>
#define len 80 

struct command{
    char cmd[len];        
    char arg[len];
    char flag[len];
};

void display(){
    printf("--- Terminal ---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n*All commands end in <space>*\n" );

}

void trim_n(char* string)
{
    size_t size = strlen(string);
    if((string[size-1]=='\n')&& (size> 0))
        string[size-1] ='\0';
}

int main()
{       
    int active =1;
    char buff[len];
    display();

    while(active==1){
        char command_temp[len] [len]; 
        char str[3*len];

        fgets(str,3*len, stdin);  
        int j =0;
        int spaces=0;
        for (int i = 0; i <= strlen(str) ; ++i)
        {
            if(str[i] == '\0' || str[i] == ' ' )
            {
                command_temp[spaces][j]='\0';
                j=0;
                spaces++;
            }
            else
            {
                command_temp[spaces][j]=str[i];
                j++;
            }
        }
        struct command c;
        char test[len];
        trim_n(command_temp[0]);
        trim_n(command_temp[1]);
        trim_n(command_temp[2]);
        strcpy(c.cmd,command_temp[0]);
        strcpy(c.flag,command_temp[1]);
        strcpy(c.arg,command_temp[2]);

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

        break;
    }
    return 0;
}



























