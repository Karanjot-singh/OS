#include <semaphore.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <sys/shm.h>

sem_t semaphore1 ;
pthread_mutex_t mutex ;
int reader_count = 0 ;
int mem_id ;
key_t key ;


void *writer(void *wno )
{
	sem_wait(&semaphore1 ) ;
	int *ptr = (int * )shmat(mem_id, (void * )0, 0 ) ;
	*ptr = 5 ;
	printf(" Writer%d- writes %d\n", (*( (int * )wno ) ), *ptr ) ;
	shmdt(ptr ) ;

	sem_post(&semaphore1 ) ;
}
void *reader(void *rno )
{
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

int main( )
{
	key = ftok("Karanjot", 65 ) ;
	mem_id = shmget(key, 1024, 0666 | IPC_CREAT ) ;


	pthread_t read[10], write[5] ;
	pthread_mutex_init(&mutex, NULL ) ;
	sem_init(&semaphore1, 0, 1 ) ;

	int a = 1 ;
	int b = 2 ;
	pthread_create(&write[0], NULL, (void * )writer, (void * )&a ) ;
	pthread_create(&read[0], NULL, (void * )reader, (void * )&a ) ;
	pthread_create(&read[1], NULL, (void * )reader, (void * )&b ) ;
	pthread_join(write[0], NULL ) ;
	pthread_join(read[0], NULL ) ;
	pthread_join(read[1], NULL ) ;

	pthread_mutex_destroy(&mutex ) ;
	sem_destroy(&semaphore1 ) ;
	return 0 ;
}