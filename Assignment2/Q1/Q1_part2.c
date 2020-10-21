/* Name: Karanjot Singh
   Roll_Number: 2019050 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
int counter = 10;

void *parent_thread()
{
	printf("Parent thread\n");

	while (counter != 100)
	{
		++counter;
		printf("%d ", counter);
	}
	printf("\n");
}
void *child_thread()
{
	printf("Child thread\n");

	while (counter != -90)
	{
		--counter;
		printf("%d ", counter);
	}
	printf("\n");
}

int main()
{
	pthread_t parent;
	pthread_t children;

	int thread1 = pthread_create(&parent, NULL, parent_thread, NULL);
	if (thread1)
	{
		perror("Error in creating thread");
		exit(1);
	}
	child_thread();
	int thread2 = pthread_create(&parent, NULL, child_thread, NULL);
	if (thread2)
	{
		perror("Error in creating thread");
		exit(1);
	}
	pthread_exit(NULL);
	return 0;
}