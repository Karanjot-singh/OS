#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 

/*
This program provides a possible solution for first readers writers problem using mutex and semaphore.
I have used 10 readers and 5 producers to demonstrate the solution. You can always play with these values.
*/

pthread_mutex_t mutex;
sem_t semaphore1;
int cnt,shmid;
cnt = 1;
key_t key;

int reader_count = 0;

void *writer(void *wno)
{
	sem_wait(&semaphore1);
	char *str = (char*) shmat(shmid,(void*)0,0);
	str="Testing";
    shmdt(str); 
	printf("Writer %d modified cnt to %s\n", (*((int *)wno)), str);
	sem_post(&semaphore1);
}
void *reader(void *rno)
{
	// Reader acquire the lock before modifying reader_count
	pthread_mutex_lock(&mutex);
	reader_count++;
	if (reader_count == 1)
	{
		sem_wait(&semaphore1); // If this id the first reader, then it will block the writer
	}
	pthread_mutex_unlock(&mutex);
	// Reading Section
    key_t key = ftok("Karanjot",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Data read from memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
    
    // destroy the shared memory 
    shmctl(shmid,IPC_RMID,NULL);
	printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

	// Reader acquire the lock before modifying reader_count
	pthread_mutex_lock(&mutex);
	reader_count--;
	if (reader_count == 0)
	{
		sem_post(&semaphore1); // If this is the last reader, it will wake up the writer.
	}
	pthread_mutex_unlock(&mutex);
}

int main()
{
	key = ftok("Karanjot", 65);
	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	pthread_t read[10], write[5];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&semaphore1, 0, 1);

	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Just used for numbering the producer and consumer


	for (int i = 0; i < 5; i++)
	{
		pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
	}
		for (int i = 0; i < 10; i++)
	{
		pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
	}


	for (int i = 0; i < 5; i++)
	{
		pthread_join(write[i], NULL);
	}
	for (int i = 0; i < 10; i++)
	{
		pthread_join(read[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&semaphore1);

	return 0;
}