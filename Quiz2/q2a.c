#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_st
{
	long type;
	char text[500];
};

int main()
{
	key_t ID = ftok("Karanjot", 65);
	struct msg_st msg;
	int msg_no = msgget(ID, 0666 | IPC_CREAT);
	char content[2000];
	int fd = open("para1.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("Error ");
		return -1;
	}

	read(fd, content, sizeof(content) - 1);
	/*Process Data for getData()*/
	content[998] = '\n';
	content[999] = '\n';
	
	content[2000] = '\0';
	int prev_index = 0;
	int char_count = 0;
	char ch = '\0';
	for (int i = 0; i < 2000; i++)
	{
		// printf("%c",content[i] );

		if (content[i] == ' ')
		{
			char buff[500];
			strncat(buff, &content[prev_index], char_count);
			strncat(buff, &ch, 1);
			printf("%s\n", buff);
			strcpy(msg.text, buff);
			msg.type = 1;
			msgsnd(msg_no, &msg, sizeof(msg), 0);
			prev_index += char_count + 1;
			char_count = 0;
			strcpy(buff, "");
		}
		else if (content[i] == '\n' && content[i + 1] == '\n')
			break;
		else
			char_count++;
	}

	close(fd);
}
