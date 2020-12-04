#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
// #include <semaphore.h>
#define TRUE 1
#define MAX 50
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

int num_forks;
//Max 50 philosophers
int state[MAX]; //0 while eating 1 when ready to eat
int phil[MAX];

my_semaphore *semaphore_array[MAX];
my_semaphore *bowl1,bowl2;
my_semaphore *fork_mutex;

void setValues()
{
    for (int i = 0; i < MAX; i++)
        phil[i] = i;
}
int leftForkNumber(int philosopherNo)
{
    return (philosopherNo + 4) % (num_forks);
}
int rightForkNumber(int philosopherNo)
{
    return (philosopherNo + 1) % (num_forks);
}

void eat(int philosopherNo)
{
    if (state[philosopherNo] == 1)
    {
        // If right and left philosopher arent eating
        if (state[rightForkNumber(philosopherNo)] != 0 && state[leftForkNumber(philosopherNo)] != 0)
        {

            printf("Philosopher %d receives fork no. %d and %d\n", philosopherNo + 1, leftForkNumber(philosopherNo) + 1, philosopherNo + 1);
            sem_wait(&bowl1);
            printf("Philosopher %d acquired bowl 1\n", philosopherNo + 1);
            sem_wait(&bowl2);
            printf("Philosopher %d acquired bowl 2\n", philosopherNo + 1);

            printf("Philosopher %d eats!\n", philosopherNo + 1);
            //eating
            state[philosopherNo] = 0;
            sem_post(&semaphore_array[philosopherNo]);
            // To avoid deadlock in case context switch after releasing bowl 1
            printf("Philosopher %d released bowl 2\n", philosopherNo + 1);

            sem_post(&bowl2);
            printf("Philosopher %d released bowl 1\n", philosopherNo + 1);

            sem_post(&bowl1);

        }
        //Right
        else if (state[rightForkNumber(philosopherNo)] != 0)
        {
            printf("Philosopher %d receives fork no. %d\n", philosopherNo + 1, philosopherNo + 1);
        }
        //left
        else if (state[leftForkNumber(philosopherNo)] != 0)
        {
            printf("Philosopher %d receives fork no. %d\n", leftForkNumber(philosopherNo) + 1, leftForkNumber(philosopherNo) + 1);
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
    printf("Philosopher %d puts down fork %d and %d \n", philosopherNo + 1, leftForkNumber(philosopherNo) + 1, philosopherNo + 1);
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

void initi(my_semaphore *s){
    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->mutex), NULL);
}

int main()
{
    printf("Enter Number of Philosophers:\n");
    scanf("%d", &num_forks);
    setValues();
    pthread_t thread_id[num_forks];
    initi(fork_mutex);
    initi(bowl1);
    sem_init(&fork_mutex, 0, 1);
    sem_init(&bowl1, 0, 1);

    for (int i = 0; i < num_forks; ++i)
    {
        initi(&semaphore_array[i]);
        sem_init(&semaphore_array[i], 0, 0);
        pthread_create(&thread_id[i], NULL, philospherRoutine, &phil[i]);

        printf("Philosopher %d is thinking\n", i + 1);
    }
    sem_init(&bowl2, 0, 1);
    for (int i = 0; i < num_forks; ++i)
        pthread_join(thread_id[i], NULL);
}