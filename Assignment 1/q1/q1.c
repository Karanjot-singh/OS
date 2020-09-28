#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
#include <sys/types.h>
#include<string.h>
#include <stdlib.h>


void getData(char buffer[]){
	char *token;
	token = strtok(buffer,"," );
	float marks=0;
	int iteration=0;
	while(token!=NULL){
		iteration++;
		if(iteration==1)
		{	
			printf("Student ID: %s | ",token);
			marks=0;
		}
		else if(iteration==2)
		{
			printf("Section: %s | ",token);			
			marks=0;
		}
		else if(iteration==3)
		{
			marks+= atof(token);

		}
		else if(iteration==4)
		{
			marks+= atof(token);
		}
		else if(iteration==5)
		{
			marks+= atof(token);
		}
		else if(iteration==6)
		{
			marks+= atof(token);
		}
		token = strtok(NULL,",");
	}
	marks=marks/4;
	printf( "Average Marks:- %.2f \n",marks);	   
}

int main(){
	pid_t pid;
	int status;
	pid = fork();

	if(pid<0){
		printf("Error in fork process");
		return 1;
	}

	else if(pid ==0){
	//child process
		printf("Child Process:\n");
		char content[7000];
		int fd = open( "file.csv", O_RDONLY );

		if (fd < 0){
			perror("Error ");
			return -1;
		}

		read (fd,content,sizeof(content)-1);
		/*Process Data for getData()*/
		content[7000]='\0';
		int count =0;
		int prev_index=0;
		int char_count=0;
		char ch ='\0';
		for(int i =0 ; i<7000;i++){
	    	// printf("%c",content[i] );

			if (content[i]=='\n')
			{	
				count++;
				char buff[100];
				strncat(buff,&content[prev_index],char_count);
				strncat(buff,&ch,1);			
				if (count>1)
				{	
					// printf("%s\n",buff);
					getData(buff);
				}
				prev_index+=char_count+1;
				char_count=0;
				strcpy(buff,"");

			}
			else if(content[i]=='B'){
				//For reading only sec A marks
				break;
			}
			else
				char_count++;
		}

		close(fd);
		exit(0);
	}

	else{
	// parent
		printf("\nParent Process:\n");
		pid_t parent_id = waitpid(pid, &status, 0);
		char content[7000];
		int fd = open( "file.csv", O_RDONLY );

		if (fd < 0){
			perror("Error ");
			return -1;
		}

		read (fd,content,sizeof(content)-1);
		/*Process Data for getData()*/
		content[7000]='\0';
		int count =0;
		int prev_index=0;		
		int char_count=0;
		char ch ='\0';

		// Loop 1 to skip through All section A students
		for(int i =0 ; i<7000;i++){
			if (content[i]=='\n')
			{	
				count++;
				prev_index+=char_count+1;
				char_count=0;
			}
			else if(content[i]=='B'){
				//For reading only sec A marks
				break;
			}
			else
				char_count++;
		}

		char secB[4000];
		strncat(secB,&content[prev_index],7000-prev_index);
		printf("\n");
		count =0;
		prev_index=0;		
		char_count=0;
		// Slightly modified version of child process function
		for(int i =0 ; i<4000;i++){
	    	// printf("%c",secB[i] );

			if (secB[i]=='\n')
			{	
				count++;
				char buff2[100];
				strncat(buff2,&secB[prev_index],char_count);
				strncat(buff2,&ch,1);			
				if (count>1)
				{	
					// printf("%s\n",buff2);
					getData(buff2);
				}
				prev_index+=char_count+1;
				char_count=0;
				strcpy(buff2,"");

			}
			else if (secB[i]=='@')
			{	
				count++;
				char buff3[100];
				strncat(buff3,&secB[prev_index],char_count);
				strncat(buff3,&ch,1);			
				if (count>1)
				{	
					// printf("%s\n",buff3);
					getData(buff3);
				}
				prev_index+=char_count+1;
				char_count=0;
				strcpy(buff3,"");

			}
			else
				char_count++;
		}	

		close(fd);
	}
	return 0;

}