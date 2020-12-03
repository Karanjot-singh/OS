#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct
{
    pthread_mutex_t lock;
    pthread_cond_t wait;
    int counter;
    int waiters;
} my_semaphore;

my_semaphore *s;


my_semaphore *InitSem(int count)
{
    my_semaphore *s;

    s = (my_semaphore *)malloc(sizeof(my_semaphore));
    if (s == NULL)
    {
        return (NULL);
    }
    s->counter = count;
    s->waiters = 0;
    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->lock), NULL);

    return (s);
}

void P(my_semaphore *s)
{
    pthread_mutex_lock(&(s->lock));

    s->counter--;

    while (s->counter < 0)
    {
        /*
                 * maintain my_semaphorephore invariant
                 */
        if (s->waiters < (-1 * s->counter))
        {
            s->waiters++;
            pthread_cond_wait(&(s->wait), &(s->lock));
            s->waiters--;
        }
        else
        {
            break;
        }
    }

    pthread_mutex_unlock(&(s->lock));

    return;
}

void V(my_semaphore *s)
{

    pthread_mutex_lock(&(s->lock));

    s->counter++;

    if (s->counter <= 0)
    {
        pthread_cond_signal(&(s->wait));
    }

    pthread_mutex_unlock(&(s->lock));
}



void* thread() 
{ 
    //wait 
    P(s); 
    printf("\nEntered..\n"); 
  
    //critical section 
    sleep(4); 
      
    //signal 
    printf("\nJust Exiting...\n"); 
    V(s); 
} 
  
  
int main() 
{ 
    s = (my_semaphore *)malloc(sizeof(my_semaphore));
    if (s == NULL)
    {
        return (NULL);
    }
    s->counter = 1;
    s->waiters = 0;
    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->lock), NULL);
    // sem_init(&s, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    // sem_destroy(&s); 
    return 0; 
} 