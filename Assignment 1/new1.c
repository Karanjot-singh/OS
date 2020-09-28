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
		char content[7000];
		int fd = open( "file.csv", O_RDONLY );

		if (fd < 0){
			return 1;
			printf("Error\n");
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
		// pid_t parent_id = waitpid(pid, &status, 0);
		// 		char content[7000];
		// int fd = open( "file.csv", O_RDONLY );

		// if (fd < 0){
		// 	return 1;
		// 	printf("Error\n");
		// }

		// read (fd,content,sizeof(content)-1);

		// content[7000]='\0';
		// int count =0;
		// int prev_index=0;
		// int char_count=0;
		// char ch ='\0';
		// for(int i =0 ; i<7000;i++){
	 //    	// printf("%c",content[i] );

		// 	if (content[i]=='\n')
		// 	{	
	 //    		// printf("p%d c%d\n",prev_index,char_count );
		// 		count++;
		// 		char buff[100];
		// 		strncat(buff,&content[prev_index],char_count);
		// 		strncat(buff,&ch,1);			
		// 		if (count>1)
		// 		{	
		// 			printf("%s\n",buff);
		// 			// getData(buff);
		// 		}
		// 		prev_index+=char_count+1;
		// 		char_count=0;
		// 		strcpy(buff,"");

		// 	}
		// else if(content[i]=='A' && count>1){
		// 		//For reading only sec B marks
		// 		break;
		// 	}
		// 	else if(content[i]=='@'){
		// 		char temp[100];
		// 		strncat(temp,&content[prev_index],char_count);
		// 		strncat(temp,&ch,1);
		// 		printf("%s\n",temp);
		// 		// getData(temp);
		// 		prev_index+=char_count+1;
		// 		char_count=0;
		// 		break;
		// 	}
		// 	else
		// 		char_count++;
		// }

		// close(fd);

	}
	return 0;

}