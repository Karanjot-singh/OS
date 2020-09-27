#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
#include <sys/types.h>
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
		char content[400];
		int fd = open("", O_RDONLY );
		if ( fd < 0 )
        return 1;

	    off_t fileLength = lseek( fd, 0, SEEK_END );  // goes to end of file
	    if ( fileLength < 0 )
	        return 1;
	    ssize_t bytes = read (fd,content,sizeof(content)-1);
	    content[400]='\0';
	    write(1,content,bytes);
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
// void getData(char *buff); 
// int main() 
// { 
// 	FILE *fp = fopen("D:\\Test.csv","r"); 
//     int count=0; 
// 	do 
// 	{ 
// 	 char buff[1024]; 
// 	 fgets(buff, 1024, (FILE*)fp); 
// 	 count++; 
// 	 if(count != 1) 
// 	 { 
// 	  printf(buff); 
// 	  getData(buff); 
// 	 } 
// 	 getch(); 
// 	}while((getc(fp))!=EOF); 
 
	 
// } 
// void getData(char buff[]) 
// { 
//    char *token = strtok(buff,","); 
//    int counter=0; 
 
//    while( token != NULL )  
//    { 
//  counter++;  
// printf( " %s\n",token); 
//       token = strtok(NULL,","); 
//    }	   
// } 

