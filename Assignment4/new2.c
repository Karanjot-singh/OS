/* philosophers.c
 * An example of the dining philosophers problem using exactly 5 philosophers.
 * This program can be modified to use different numbers of philosophers.
 *
 */

#include <pthread.h>   //Allow for pthread barriers, attributes, and thread creation
#include <semaphore.h> //Allow for semaphores
#include <stdio.h>     //Provide I/O
#include <stdlib.h>    //Use NULL
#include <unistd.h>    //Use usleep (sleep for a number of microseconds)

#define NUM_PHIL 5 //The number of philosophers
#define MEALS 100  //The number of meals per philosopher

static sem_t chopsticks[NUM_PHIL];   //Semaphores to represent chopsticks
// static pthread_barrier_t my_barrier; //Variable for the barrier

/*  This function represents the philosopher threads.  Each philosopher must
 *  wait until all others have started before continuing.  Each then eats NUM_PHIL
 *  meals.  Philosophers must acquire chopsticks (semaphores) to their left and 
 *  right before eating.
 */
void *philosopher(void *tid)
{
    //Wait for all threads to start
    // pthread_barrier_wait(&my_barrier);

    //Set up variables for the thread id, right chopstick, and left chopstick.
    int id = (int)tid;
    int right_chopstick;
    int left_chopstick;

    //Philosophers 0 through NUM_PHIL-2 reach to the left first then the right.
    if (id < NUM_PHIL - 1)
    {
        right_chopstick = id;
        left_chopstick = id + 1;
    }
    //Philosopher NUM_PHIL-1 has its left and right swapped.  Notice that it reaches in the
    //opposite order of all other philosophers.
    else
    {
        right_chopstick = 0;
        left_chopstick = id;
    }

    //Acquire chopsticks (semaphores), eat, wait for 100 microseconds, then release
    //chopsticks (semaphores).
    int i;
    sem_wait(&chopsticks[left_chopstick]);
    sem_wait(&chopsticks[right_chopstick]);

    printf("philosopher %d is eating\n", id);
    usleep(100);

    sem_post(&chopsticks[left_chopstick]);
    sem_post(&chopsticks[right_chopstick]);
    pthread_exit(NULL);
}

//Main function.
int main(int argc, char **argv)
{
    int i;

    pthread_t philosophers[NUM_PHIL];                  //Thread variables to represent each philosopher
    // pthread_barrier_init(&my_barrier, NULL, NUM_PHIL); //Initialize the barrier to allow for
                                                       //NUM_PHIL threads.

    //Initialize semaphores
    for (i = 0; i < NUM_PHIL; i++)
        sem_init(&chopsticks[i], 0, 1);

    //Create and start philosopher threads.
    for (i = 0; i < NUM_PHIL; i++)
        pthread_create(&philosophers[i], NULL, philosopher, (void *)i);

    //Wait for philosophers to finish.
    for (i = 0; i < NUM_PHIL; i++)
        pthread_join(philosophers[i], NULL);

    //Destroy semaphores.
    for (i = 0; i < NUM_PHIL; i++)
        sem_destroy(&chopsticks[i]);

    //Destroy other thread variables.
    // pthread_barrier_destroy(&my_barrier);

    //End program.
    pthread_exit(NULL);
    return 0;
}