#include <stdio.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
#include <sys/types.h>

// Your task is to design your a simple shell that can handle five, internal commands –
 // ‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’. These commands
// external commands – ‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’.


void display(){
	printf("---Terminal---\n Available commands:\n‘cd’, ‘echo’, ‘history’, ‘pwd’ and ‘exit’\n‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’\n" );

}
int main(){
	display();	
	printf("Enter command number: \n");
	int choice,loopf =1;
	while(loopf){ 
		scanf("%d",&choice);
		if(choice>=1 && choice <=10){
			printf("Command selected!\n");
		}
		else
			printf("Enter valid command number!!\n");
	}
	switch(choice){
		case 1:{

		}
		case 2:{
			
		}
		case 3:{
			
		}
		case 4:{
			
		}
		case 5:{
			
		}
		case 6:{
			
		}
		case 7:{
			
		}
		case 8:{
			
		}
		case 9:{
			
		}
		case 10:{
			
		}

	}




	return 0;
}