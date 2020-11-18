#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_st
{
	long type;
	char text[500];
};

int main()
{
	struct msg_st msg;
	key_t ID = ftok("Karanjot", 65);
	;
	int msg_no = msgget(ID, 0666 | IPC_CREAT);
	msgrcv(msg_no, &msg, sizeof(msg), 1, 0);
	printf("Data Received is : %s \n",
		   msg.text);
	msgctl(msg_no, IPC_RMID, NULL);
	return 0;
}
