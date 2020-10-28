#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_task_info 440

long task_info_syscall(int pid1, char* filenm)
{
    return syscall(__NR_task_info,pid1,filenm);
}

int main(int argc, char *argv[])
{
    long syscall_working;
    char file[256];
    int pid1;
    printf("Enter the pid: \n");
    scanf("%d",&pid1);
    printf("Enter the File Name: \n");
    scanf("%s",file );
    syscall_working = task_info_syscall(pid1,file);

    if(syscall_working <0)
    {
        perror("Error ");
    }
    else
        printf("Success! Data written to file.\n");
    return 0;
}
