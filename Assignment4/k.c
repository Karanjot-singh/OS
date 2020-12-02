#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Semaphore
// {
//     int n;
//     mutex *m_count; //unlocked initially
//     mutex *m_queue; //locked initially
// };

struct countingSemaphore
{
    int count;
    pthread_mutex_t numLock; //For locking the number of semaphores allowed into CS U
    pthread_mutex_t csLock;  // For entry to the critical section Q

} my_semaphore;

void wait()
{
    // m_count.lock();
    pthread_mutex_lock(&my_semaphore.numLock);
    my_semaphore.count -= 1;
    if (my_semaphore.count < 0)
    {
        // m_count.unlock();
        pthread_mutex_unlock(&my_semaphore.numLock);
        // m_queue.lock();     //wait
        pthread_mutex_lock(&my_semaphore.csLock);
    }
    // m_count.unlock();       //unlock signal's lock
    pthread_mutex_unlock(&my_semaphore.csLock);
}

void signal()
{
    // m_count.lock();
    pthread_mutex_lock(&my_semaphore.numLock);
    // n = n+1;
    my_semaphore.count += 1;
    // if(n <= 0){
    if (my_semaphore.count <= 0)
    {
        // m_queue.unlock();   //leave m_count locked
        pthread_mutex_unlock(&my_semaphore.csLock);
    }
    else
    {
        // m_count.unlock();
        pthread_mutex_unlock(&my_semaphore.numLock);
    }
}

int main()
{

    if (pthread_mutex_init(&my_semaphore.numLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
}