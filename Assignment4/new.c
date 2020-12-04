#include <stdio.h>

#include <pthread.h>

#include <stdlib.h>

#include <unistd.h>

#include <ctype.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <semaphore.h>

#include <sys/sem.h>

sem_t chopstick[100];
sem_t lock;

int n;

void *thread_func(int no)

{
    while(1){
    if(no == n-1)
    {

        sem_wait(&chopstick[(no + 1) % n]);
        printf("\nPhilosopher %d  takes fork %d", no,(no + 1) % n);

        sem_wait(&chopstick[no]);
        printf("\nPhilosopher %d  takes fork %d", no,no);
    }
    else{

        sem_wait(&chopstick[no]);
        printf("\nPhilosopher %d  takes fork %d", no,no);


        sem_wait(&chopstick[(no + 1) % n]);
        printf("\nPhilosopher %d  takes fork %d", no,(no + 1) % n);
    }
        // sem_wait(&lock);
        printf("\nPhilosopher %d –> Begin eating", no);
        printf("\nPhilosopher %d –> Finish eating\n", no);
        // sem_post(&lock);
        sem_post(&chopstick[no]);

        sem_post(&chopstick[(no + 1) % n]);
    // pthread_exit(NULL);
    
    }
}

int main()

{

    int i, res;

    pthread_t a_thread[100];

    printf("\nEnter the number of philosopher:");

    scanf("%d", &n);

    for (i = 0; i < n; ++i)

    {

        res = sem_init(&chopstick[i], 0, 0);
        sem_init(&lock,0,1);

        if (res == -1)

        {

            perror("semaphore initialization failed");

            exit(1);
        }
    }

    for (i = 0; i < n; ++i)

    {

        res = pthread_create(&a_thread[i], NULL, thread_func, (int *)i);

        if (res != 0)

        {

            perror("semaphore creation failed");

            exit(1);
        }

        sem_post(&chopstick[i]);
    }

    for (i = 0; i < n; ++i)

    {

        pthread_join(a_thread[i], NULL);
    }

    printf("\n \n thread join succesfull\n");

    exit(0);
}