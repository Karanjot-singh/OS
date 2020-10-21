/* Name: Karanjot Singh
   Roll_Number: 2019050 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int counter = 10;

int main()
{
	pid_t pid;
	int status;
	pid = fork();

	if (pid < 0)
	{
		perror("Error in fork process");
		return 1;
	}

	else if (pid == 0)
	{
		//child process
		printf("Child Process- Pid: %d \n", getpid());
		while (counter != -90)
		{
			--counter;
			printf("%d ", counter);
		}
		printf("\n");
		exit(0);
	}

	else
	{
		// parent
		pid_t parent_id = waitpid(pid, &status, 0);
		printf("\nParent Process- Pid: %d \n", getpid());
		while (counter != 100)
		{
			++counter;
			printf("%d ", counter);
		}
		printf("\n");
		return 0;
	}
}
