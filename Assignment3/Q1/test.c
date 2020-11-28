/* Name: KARANJOT SINGH
   Roll_Number: 2019050*/
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#define __NR_rtnice 440
#define MAX 3000000000

long syscall_rt(int pid1, long srt)
{
    // In seconds
    return syscall(__NR_rtnice,pid1,srt);
}

int main( int argc, char *argv[] )
{
    long int syscall_working;
    long int srt;
    printf("Enter the Soft real time requirements (s): \n");
    scanf("%ld",&srt);
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Error in fork process");
        return 1;
    }

    if (pid == 0)
    {
        //child process
        syscall_working = syscall_rt(getpid(),srt);
        if(syscall_working !=0)
        {
            perror("Error ");
            return -1;
        }
        struct timeval s, e;
        gettimeofday(&s,0);
        long temp=0;
        for (long i = 0; i < MAX; ++i)
        { 
            temp++;
        }
        gettimeofday(&e,0);
        long difference;
        difference = ((e.tv_sec-s.tv_sec)*1000000+(e.tv_usec-s.tv_usec));
        printf("Modified scheduler time: %f\n",difference/1000000.00000);
    }
    else{
 
        struct timeval s, e;
        long temp=0;
        gettimeofday(&s,0);
        for (long i = 0; i < MAX; ++i)
        { 
            temp++;
        }
        gettimeofday(&e,0);
        long difference;
        difference = ((e.tv_sec-s.tv_sec)*1000000+(e.tv_usec-s.tv_usec));
        printf("CFS scheduler time: %f\n",difference/1000000.00000);

        waitpid(-1 ,NULL ,0);
    }

    return 0;
}
