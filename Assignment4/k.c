#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t wait;
    int counter;
    int waiting_threads;
} my_semaphore;


void sem_init(my_semaphore *s,int temp, int count)
{
    s = (my_semaphore *)malloc(sizeof(my_semaphore));
    if (s == NULL)
    {
        perror("Error: ");
        return;
    }
    s->waiting_threads = 0;
    s->counter = count;
    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->mutex), NULL);
}

void sem_wait(my_semaphore *s)
{
    pthread_mutex_lock(&(s->mutex));
    s->counter--;

    while (s->counter < 0)
    {
        //Invariant incase pthread_cond_signal releases more than 1 thread fro the blocked queues
        if (s->waiting_threads < (-1 * s->counter))
        {
            s->waiting_threads++;
            pthread_cond_wait(&(s->wait), &(s->mutex));
            s->waiting_threads--;
        }
        else
        {
            break;
        }
    }

    pthread_mutex_unlock(&(s->mutex));

    return;
}

void sem_post(my_semaphore *s)
{

    pthread_mutex_lock(&(s->mutex));

    s->counter++;

    if (s->counter <= 0)
    {
        pthread_cond_signal(&(s->wait));
    }

    pthread_mutex_unlock(&(s->mutex));
}

void *thread()
{
    // //wait
    // sem_wait(s);
    // printf("\nEntered..\n");

    // //critical section
    // sleep(4);

    // //signal
    // printf("\nJust Exiting...\n");
    // sem_post(s);
}

int main()
{
    my_semaphore *s;    

    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->mutex), NULL);
    // sem_init(&s, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // sem_destroy(&s);
    return 0;
}