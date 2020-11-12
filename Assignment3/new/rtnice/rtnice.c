#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/init.h>

struct task_struct *t_struct;
int ret_flag=0;

SYSCALL_DEFINE2(rtnice, int, pid1, unsigned long long, soft_requirements )
{

  printk(KERN_INFO "System call functional");
  if( soft_requirements <0)
  	return -1;//EPERM
  t_struct= get_pid_task( find_get_pid(pid1), PIDTYPE_PID );
  if (t_struct == NULL){
    return -3;//ESRCH
  }
  t_struct->se.rtnice= soft_requirements;
  printk( "rtnice value set to %llu \n", t_struct->se.rtnice );

  return 0;
}
