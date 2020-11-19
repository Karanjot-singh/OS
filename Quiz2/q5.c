#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*
This program provides a possible solution for first readers writers problem using mutex and semaphore.
I have used 10 readers and 5 producers to demonstrate the solution. You can always play with these values.
*/

pthread_mutex_t mutex ;
sem_t semaphore1 ;
int reader_count = 0 ;
int mem_id ;
key_t key ;


void *writer(void *wno )
{
	sem_wait(&semaphore1 ) ;
	// str="Testing" ;
	// shmdt(str ) ;
	int *ptr = (int * )shmat(mem_id, (void * )0, 0 ) ;
	*ptr = 5 ;
	printf(" Writer%d- writes %d\n", (*( (int * )wno ) ), *ptr ) ;
	shmdt(ptr ) ;
	sem_post(&semaphore1 ) ;
}
void *reader(void *rno )
{
	// Reader acquire the lock before modifying reader_count
	pthread_mutex_lock(&mutex ) ;
	reader_count++ ;
	if (reader_count == 1 )
	{
		sem_wait(&semaphore1 ) ; // If this id the first reader, then it will block the writer
	}
	pthread_mutex_unlock(&mutex ) ;
	// Reading Section
	int *ptr = (int * )shmat(mem_id, ( void * )0, 0 ) ;
	printf(" Reader%d- reads %d\n", *( ( int * )rno ), *ptr ) ;
	shmdt(ptr ) ;
	shmctl(mem_id, IPC_RMID, NULL ) ;

	// Reader acquire the lock before modifying reader_count
	pthread_mutex_lock(&mutex ) ;
	reader_count-- ;
	if (reader_count == 0 )
	{
		sem_post(&semaphore1 ) ; // If this is the last reader, it will wake up the writer.
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