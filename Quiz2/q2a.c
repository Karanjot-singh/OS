#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct msg_st { 
	long type; 
	char text[500]; 
};

int main() 
{ 	
	key_t ID  = ftok("Karanjot", 65); 
	struct msg_st msg;
	int msg_no = msgget(ID, 0666 | IPC_CREAT); 
	printf("Write Data : "); 
	gets(msg.text);
		msg.type = 1; 
	msgsnd(msg_no, &msg, sizeof(msg), 0); 
	printf("Data send is : %s \n", msg.text); 

	return 0; 
} 
