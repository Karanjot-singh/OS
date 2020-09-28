#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
#include <sys/types.h>
#include<string.h>


void getData(char buffer[]){
   char *token;
   int ct=0;
   	token = strtok(buffer,", \n" );

   for (int i = 0; i < 6; ++i)
   {
   	 token = strtok(NULL,",");
   }
   while(token!=NULL){ 
 	ct++;
	printf( "%s\n",token);
    token = strtok(NULL,",");
      
   }	   
}
void processData(char buffer[]){
   char *token;    	
   char temp[100];
   	token = strtok(buffer,"\n" );
   while(token!=NULL){ 
	strcpy(temp,token);
	// getData(temp);

	printf( "%s\n",temp);
    token = strtok(NULL,"\n");
	// strcat(buff,token); 

   }
	// printf( "%s\n",buff);

   // getData(buff);	   
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
		int fd = open("file.csv", O_RDONLY );

		if ( fd < 0 ){
       	 return 1;
       	 printf("Error\n");
    }

	    // ssize_t bytes = read (fd,content,sizeof(content)-1);
	    read (fd,content,sizeof(content)-1);

	    content[7000]='\0';
	    int count =0;
	    
    	int prev_index=0;
    	int char_count=0;
	    for(int i =0 ; i<7000;i++){
	    	// printf("%c",content[i] );

	    	if (content[i]=='\n')
	    	{	
	    		// printf("p%d c%d\n",prev_index,char_count );
			    char buff[100];
			    strncat(buff,&content[prev_index],char_count);
			    printf("%s\n",buff);
			    prev_index+=char_count+1;
			    char_count=0;
			    strcpy(buff,"");

	    	}
	    	else if(content[i]=='@'){
	    		char temp[100];
	    		strncat(temp,&content[prev_index],char_count);
			    printf("%s\n",temp);
			    prev_index+=char_count+1;
			    char_count=0;
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
		pid_t parent_id = waitpid(pid, &status, 0);


	}
	return 0;

}