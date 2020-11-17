#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

unsigned long long nCr(unsigned long long n, unsigned long long r)
{
	if(n>=r)
	{
		if(r==0 || r==n)
		{
			return 1;
		}
		else
		{
			return nCr(n-1,r-1) + nCr(n-1,r);
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	long int pid=fork();

	if(pid!=0)
	{
		long ret = syscall(323,pid,200);
		printf("%s\n",strerror(ret));
		long ret2 = syscall(323,getpid(),200);
		printf("%s\n",strerror(ret2));
	}

	if(pid==0)
	{
		unsigned long long ans = nCr(30,15);
		printf("Finished calculating 30C15\n");
		printf("Process with PID %ld finished\n",getpid());
	}
	else
	{
		unsigned long long ans = nCr(24,12);
		printf("Finished calculating 24C12\n");
		printf("Process with PID %ld finished\n",getpid());
		wait(pid);
	}
	return 0;
}
