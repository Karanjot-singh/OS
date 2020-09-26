#include <stdio.h>
#include <unistd.h>
#include<stdlib.h> 
#include<sys/wait.h> 
#include <sys/types.h>
int main(){
	pid_t pid;
	int status;
	pid = fork();

	if(pid<0){
		printf("Error");
	return 1;
	}

	else if(pid ==0){
	//child process

		exit(0);
	}

	else{
	// parent
		pid_t parent_id = waitpid(pid, &status, 0);

	}
	return 0;

}