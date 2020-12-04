#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define TRUE 1
#define MAX 50

int num_forks;
//Max 50 philosophers
int state[MAX]; //0 while eating 1 when ready to eat
int phil[MAX];
int flag=0;

sem_t semaphore_array[MAX];
sem_t bowls[2];
sem_t bowl_mutex;
sem_t fork_mutex;

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
            printf("Philosopher %d eats!\n", philosopherNo + 1);
            //eating
            state[philosopherNo] = 0;
            sem_post(&semaphore_array[philosopherNo]);
            // To avoid deadlock in case context switch after releasing bowl 0
            sem_post(&bowls[1]);
            sem_post(&bowls[0]);
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
    printf("lol");
    sem_wait(&fork_mutex);
    state[philosopherNo] = 1; //ready to eat state
    //If neighbours arent eating
    eat(philosopherNo);
    sem_post(&fork_mutex);
    ; // philosopher waits if unable to eat
    sem_wait(&semaphore_array[philosopherNo]);
    //bowls
    sem_wait(&bowls[0]);
    sem_wait(&bowls[1]);
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

void bowlUp(int philosopherNo)
{
    sem_wait(&bowl_mutex);
    state[philosopherNo] = -1;
            printf("Philosopher %d picked up bowl 1\n", philosopherNo + 1);
        printf("Philosopher %d picked up bowl 2\n", philosopherNo + 1);
        // forkUp(philosopherNo);
    sem_post(&bowl_mutex);
        forkUp(philosopherNo);
    sem_wait(&bowls[0]);
    sem_wait(&bowls[1]);

}
void bowlDown(int philosopherNo)
{
    sem_wait(&bowl_mutex);
    printf("Philosopher %d puts down bowls 1 & 2 \n", philosopherNo + 1);
    sem_post(&bowl_mutex);
}

void *philospherRoutine(void *num)
{
    while (TRUE)
    {
        int *temp = num;
        // sleep(1);
        // bowlUp(*temp);
        sleep(1);
        // forkUp(*temp);
        sleep(1);
        forkDown(*temp);
                sleep(1);
        bowlDown(*temp);


    }
}

int main()
{
    printf("Enter Number of Philosophers:\n");
    scanf("%d", &num_forks);
    setValues();
    pthread_t thread_id[num_forks];
    sem_init(&fork_mutex, 0, 1);
    sem_init(&bowl_mutex, 0, 1);

    for (int i = 0; i < num_forks; ++i)
    {
        sem_init(&semaphore_array[i], 0, 0);
        pthread_create(&thread_id[i], NULL, philospherRoutine, &phil[i]);

        printf("Philosopher %d is thinking\n", i + 1);
    }
    sem_init(&bowls[0], 0, 0);
    sem_init(&bowls[1], 0, 0);

    for (int i = 0; i < num_forks; ++i)
        pthread_join(thread_id[i], NULL);
}