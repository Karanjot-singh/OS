#include <stdio.h> 
#include <string.h>
#include<ctype.h>
#include <unistd.h>
#define len 80 

// CHECK SPACE =1

struct command{
    char cmd[len];        
    char arg[len];
    char flag[len];
};

void display(){
    printf("--- Terminal ---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n*All commands end in <space>*\n" );

}

int main() 
{   
    struct command c;
    int noSpace=1;
    int active =1;
    char buff1[len];
    display();

    // To get input
    while(active==1){
        char str[3*len];
        //input code for commands
        printf("terminal>");
        fgets(str, 3*len, stdin);
        int count =0;
        int prev_index=0;
        int char_count=0;
        char ch ='\0';

        for (int i = 0; i < 3*len; ++i)
        {   
            if (str[i]==' ')
            {   
                count++;
                char buff[len];
                strncat(buff,&str[prev_index],char_count);
                if(count==1)
                    strcpy(c.cmd,buff);
                else if (count==2)
                    strcpy(c.flag,buff);
                else if(count ==3)
                    strcpy(c.arg,buff);

                // printf("%s\n",buff);
                prev_index+=char_count+1;
                char_count=0;
                strcpy(buff,"");
            }
            else
                char_count++;
        }

        printf("1 %s 2 %s 3 %s\n",c.cmd ,c.flag,c.arg );
        // if(count==0)
        // {   printf("0lol\n");
            strcpy(c.cmd,str);
            strcpy(c.flag," \n");
            strcpy(c.cmd," \n");
            printf("check0 %d\n",strcmp(c.cmd,"check\n"));
            printf("check %d\n",strcmp(c.cmd,"check"));

            printf(" /n %d\n",strcmp(c.flag,"\n"));
            printf(" %d\n",strcmp(c.arg," "));

        // }
               //exit
        if(strcmp(c.cmd,"exit\n")==0 || strcmp(c.cmd,"Exit\n")==0 ){
            printf("success\n");
            break;
        }
        // else if(strcmp(c.cmd,"cd\n")==0){
        //     printf("cus\n");
        //     if(strcmp(c.flag," \n")==0 && strcmp(c.arg," \n")==0)
        //         printf("Valid format cd <directory>\n" );
        //     else if(strcmp(c.flag,"")==0)
        //     {
        //         chdir(c.arg);
        //         printf("%s\n", getcwd(buff1,len)); 
        //     }
        // }
        break;
    }

    return 0; 
} 