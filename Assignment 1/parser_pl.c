#include <stdio.h>
#include <string.h>
int main()
{
    char str[len0];
    char command_temp[len][len]; 
    int i,j,spaces; 
    fgets(str, sizeof str, stdin);	
 
    j=0; spaces=0;
    for(i=0;i<=(strlen(str));i++)
    {
        // if space or NULL found, assign NULL into command_temp[spaces]
        if(str[i]==' '||str[i]=='\0')
        {
            command_temp[spaces][j]='\0';
            spaces++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            command_temp[spaces][j]=str[i];
            j++;
        }
    }
    printf("\n Strings or words after split by space are :\n");
    for(i=0;i < spaces;i++)
        printf(" %s\n",command_temp[i]);
    return 0;
}