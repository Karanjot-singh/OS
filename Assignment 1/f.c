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
	    char buff[100];
	    int count =0;
	    for(int i =0 ; i<7000;i++){
	    	// printf("%c",content[i] );

	    	// while(content[i]=='\n'){
	    	// 	char buff[100];
	    	// 	buff[i]=content[i];

	    	// }
	    	if (content[i]=='\n')
	    	{	count++;
	    		if(count==2){

	    		}
	    		printf("%s\n",buff );
	    		strcpy(buff,"");
	    	}
	    	else{
	    		buff[i]=content[i];
	    	}
	    }
	    // while(content[i])
	    // getData(content);
	    // processData(content);
	    // printf("%s\n",content);

	    close(fd);
		exit(0);
	}

	else{
	// parent
		pid_t parent_id = waitpid(pid, &status, 0);


	}
	return 0;

}



// #include<stdio.h> 
// #include<conio.h> 
// #include<String.h> 
// void getData(char *buffer); 
// int main() 
// { 
// 	FILE *fp = fopen("D:\\Test.csv","r"); 
//     int count=0; 
// 	do 
// 	{ 
// 	 char buffer[1024]; 
// 	 fgets(buffer, 1024, (FILE*)fp); 
// 	 count++; 
// 	 if(count != 1) 
// 	 { 
// 	  printf(buffer); 
// 	  getData(buffer); 
// 	 } 
// 	 getch(); 
// 	}while((getc(fp))!=EOF); 
 
	 
// } 


