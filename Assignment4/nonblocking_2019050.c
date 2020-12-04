#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
// #include <semaphore.h>
#define TRUE 1
#define MAX 50
typedef struct sem_t
{   
    ssize_t sem_value;
    pthread_cond_t counter;  /*To provide functionality of locks*/
    pthread_mutex_t mutex; /*To provide functionality of locks*/
} sem_t;

int sem_init(sem_t *my_semaphore, int pshared, int value)
{   
    /* Function for the initialisation of the semaphores and setting the value of the condition variables
    */
    my_semaphore->sem_value = value;
    pthread_mutex_init(&my_semaphore->mutex, NULL);
    pthread_cond_init(&my_semaphore->counter, NULL);
    return 0;
}
void sem_post(sem_t *my_semaphore)
{
    if (!pthread_mutex_trylock(&my_semaphore->mutex))
    {
        // mutex locked
        // pthread_mutex_lock(&my_semaphore->mutex);
        my_semaphore->sem_value++;
        pthread_cond_signal(&my_semaphore->counter);
        pthread_mutex_unlock(&my_semaphore->mutex);
    }
}
void sem_wait(sem_t *my_semaphore)
{
    // pthread_mutex_lock(&my_semaphore->mutex);
    if (!pthread_mutex_trylock(&my_semaphore->mutex))
    {
        while (my_semaphore->sem_value == 0)
        {
            pthread_cond_wait(&my_semaphore->counter, &my_semaphore->mutex);
            /*unlock wait relock mutex*/
        }
        my_semaphore->sem_value--;
        pthread_mutex_unlock(&my_semaphore->mutex);
    }
}

int num_forks;
//Max 50 philosophers
int state[MAX]; //0 while eating 1 when ready to eat
int phil[MAX];

sem_t semaphore_array[MAX];
sem_t *bowl1, bowl2;
sem_t *fork_mutex;

void setValues()
{
    for (int i = 0; i < MAX; i++)
        phil[i] = i;
}
int leftForkNumber(int philosopherNo)
{

    return (philosopherNo + num_forks - 1) % (num_forks);
}
int rightForkNumber(int philosopherNo)
{
    return (philosopherNo + 1) % (num_forks);
}

void eat(int philosopherNo)
{
    if (state[philosopherNo] == 1)
    {
        pid_t tid = gettid();

        // If right and left philosopher arent eating
        if (state[rightForkNumber(philosopherNo)] != 0 && state[leftForkNumber(philosopherNo)] != 0)
        {

            printf("Philosopher %d acquires Fork %d and %d\n", tid, leftForkNumber(philosopherNo) + 1, tid);
            sem_wait(&bowl1);
            printf("Philosopher %d acquired Bowl 1\n", tid);
            sem_wait(&bowl2);
            printf("Philosopher %d acquired Bowl 2\n", tid);

            printf("PHILOSOPHER %d EATS\n", tid);
            //eating
            state[philosopherNo] = 0;
            sem_post(&semaphore_array[philosopherNo]);
            // To avoid deadlock in case context switch after releasing bowl 1
            printf("Philosopher %d released bowl 2\n", tid);

            sem_post(&bowl2);
            printf("Philosopher %d released bowl 1\n", tid);

            sem_post(&bowl1);
        }
        //Right
        else if (state[rightForkNumber(philosopherNo)] != 0)
        {
            printf("Philosopher %d acquires Fork %d\n", tid, tid);
        }
        //left
        else if (state[leftForkNumber(philosopherNo)] != 0)
        {
            printf("Philosopher %d acquires Fork %d\n", tid, leftForkNumber(philosopherNo) + 1);
        }
    }
}

void forkUp(int philosopherNo)
{
    // printf("lol");
    sem_wait(&fork_mutex);
    state[philosopherNo] = 1; //ready to eat state
    //If neighbours arent eating
    eat(philosopherNo);
    sem_post(&fork_mutex);
    ; // philosopher waits if unable to eat
    sem_wait(&semaphore_array[philosopherNo]);
}

void forkDown(int philosopherNo)
{

    sem_wait(&fork_mutex);
    state[philosopherNo] = 2;
    pid_t tid = gettid();

    printf("Philosopher %d puts down Fork %d\n", tid, leftForkNumber(philosopherNo) + 1);
    printf("Philosopher %d puts down Fork %d\n", tid, tid);
    eat(leftForkNumber(philosopherNo));
    ;
    eat(rightForkNumber(philosopherNo));

    sem_post(&fork_mutex);
}
void *philospherRoutine(void *num)
{
    while (TRUE)
    {
        int *temp = num;
        sleep(1);
        forkUp(*temp);
        sleep(1);
        forkDown(*temp);
    }
}

int main()
{
    printf("Enter Number of Philosophers:\n");
    scanf("%d", &num_forks);
    setValues();
    pthread_t thread_id[num_forks];
    sem_init(&fork_mutex, 0, 1);
    sem_init(&bowl1, 0, 1);

    for (int i = 0; i < num_forks; ++i)
    {
        sem_init(&semaphore_array[i], 0, 0);
        pthread_create(&thread_id[i], NULL, philospherRoutine, &phil[i]);

        // printf("Philosopher %d is thinking\n", i + 1);
    }
    sem_init(&bowl2, 0, 1);
    for (int i = 0; i < num_forks; ++i)
        pthread_join(thread_id[i], NULL);
}