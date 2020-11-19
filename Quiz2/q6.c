#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define num_forks 5
#define TRUE 1

int state[num_forks];
int phil[num_forks] = {0, 1, 2, 3, 4};

sem_t semaphore_array[num_forks];
sem_t mutex;

void test(int ph_no)
{
	if (state[ph_no] == 1)
	{
		if (state[(ph_no+1) % (num_forks)] != 0 && state[(ph_no+4) % (num_forks)] != 0 && 1)
		{
			printf("Philosopher %d receives fork no. %d and %d\n", ph_no+1, (ph_no+4) % (num_forks) + 1, ph_no+1);
			state[ph_no] = 0;
			sem_post(&semaphore_array[ph_no]);
		}
		//Right
		else if (state[(ph_no+1) % (num_forks)] != 0)
		{
			printf("Philosopher %d receives fork no. %d\n", ph_no+1, ph_no+1);
		}
		//left
		else if (state[(ph_no+4) % (num_forks)] != 0)
		{
			printf("Philosopher %d receives fork no. %d\n", (ph_no+4) % (num_forks) + 1, (ph_no+4) % (num_forks) + 1);
		}
	}
}

void fork_down(int ph_no)
{

	sem_wait(&mutex);

	state[ph_no] = 2;

	printf("Philosopher %d puts down fork %d and %d \n", ph_no+1, (ph_no+4) % (num_forks) + 1, ph_no+1);
	test((ph_no+4) % (num_forks));		;
	test((ph_no+1) % (num_forks));

	sem_post(&mutex);
}

void fork_up(int ph_no)
{	sem_wait(&mutex);
	state[ph_no] = 1;
	test(ph_no);

	sem_post(&mutex);				;
	sem_wait(&semaphore_array[ph_no]);
}

void *philospher_eat(void *num)
{
	while (TRUE)
	{
		int *i = num;
		sleep( 1 );
		fork_up(*i);
		fork_down(*i);

	}
}

int main()
{

	pthread_t thread_id[num_forks];
	sem_init(&mutex, 0, 1);
	for (int i = 0; i < num_forks; ++i)
	{
		sem_init(&semaphore_array[i], 0, 0);
		pthread_create(&thread_id[i], NULL, philospher_eat, &phil[i]);

		printf("Philosopher %d is thinking\n", i + 1);
	}
	for (int i = 0; i < num_forks; ++i)
		pthread_join(thread_id[i], NULL);
}