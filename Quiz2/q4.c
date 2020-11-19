#include <semaphore.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

sem_t semaphore1 ;
pthread_mutex_t mutex ;
int reader_count = 0 ;
int mem_id ;
key_t key ;

int main( )
{
	key = ftok("Karanjot", 65 ) ;
	mem_id = shmget(key, 1024, 0666 | IPC_CREAT ) ;

	sem_init(&mutex, 0,0 ) ;
	sem_init(&semaphore1, 0, 1 ) ;

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
	//writer
	sem_wait(&semaphore1 ) ;
	int *ptr = (int * )shmat(mem_id, (void * )0, 0 ) ;
	*ptr = 5 ;
	printf(" Writer%d- writes %d\n", (*( (int * )wno ) ), *ptr ) ;
	shmdt(ptr ) ;

	sem_post(&semaphore1 ) ;
}
else
{	
	//reader
	pthread_mutex_lock(&mutex ) ;
	reader_count++ ;
	if (reader_count==1 )
	{
		sem_wait( &semaphore1 ) ;
	}
	pthread_mutex_unlock(&mutex ) ;
	int *ptr = (int * )shmat(mem_id, ( void * )0, 0 ) ;
	printf(" Reader%d- reads %d\n", *( ( int * )rno ), *ptr ) ;

	shmdt(ptr ) ;
	shmctl(mem_id, IPC_RMID, NULL ) ;

	pthread_mutex_lock(&mutex ) ;
	reader_count-- ;


	if (reader_count==0 )
	{
		sem_post(&semaphore1 ) ;
	}
	pthread_mutex_unlock(&mutex ) ;
}


	sem_destroy(&mutex ) ;
	sem_destroy(&semaphore1 ) ;
	return 0 ;
}