#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include "rtnice.h"

asmlinkage long sys_rtnice(long givenPID, int rtnice) {
    struct task_struct *proces;
    int flag = 0;

    for_each_process(proces) {
      if((long)task_pid_nr(proces)==givenPID)
      {
        flag = 1;
        proces->se.rtnice = rtnice;
        printk("%ld\n",proces->se.rtnice);
      }
  }

  if(flag==0)
  {
    printk("No process with the given PID found\n");
  }

  return 0;
}
