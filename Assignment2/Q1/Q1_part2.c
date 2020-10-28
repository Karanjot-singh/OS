/* Name: Karanjot Singh
   Roll_Number: 2019050 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 10;

void parent_thread()
{
	while (counter != 100)
		printf("%d Parent thread\n", ++counter);
}
void *child_thread()
{
	while (counter != -90)
		printf("%d Child Thread\n", --counter);
}

int main()
{
	pthread_t children;
	int thread2 = pthread_create(&children, NULL, child_thread, NULL);
	if (thread2)
	{
		perror("Error in creating thread");
		exit(1);
	}
	parent_thread();

	pthread_exit(NULL);
	return 0;
}