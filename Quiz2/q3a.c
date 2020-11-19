// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAXL 1024
#define PORTNO 8080

void sendmsg(char *msg)
{
	int socketfd;
	char buffer[MAXL];
	struct sockaddr_in serveraddress, cliaddr;

	(socketfd = socket(AF_INET, SOCK_DGRAM, 0);

	 memset(&cliaddr, 0, sizeof(cliaddr));
	 memset(&serveraddress, 0, sizeof(serveraddress));
	 serveraddress.sin_addr.s_addr = INADDR_ANY;
	 //update server
	 serveraddress.sin_port = htons(PORTNO);
	 serveraddress.sin_family = AF_INET;

	 bind(socketfd, (const struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0);
	int length;
	int n;
	length = sizeof(cliaddr);
	n = recvfrom(socketfd, (char *)buffer, MAXL, MSG_WAITALL, (struct sockaddr *)&cliaddr, &length);
	buffer[n] = '\0';

	sendto(socketfd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, length);
	return 0;
}

int main()
{

	char content[2000];
	int fd = open("para1.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("Error ");
		return -1;
	}

	read(fd, content, sizeof(content) - 1);
	/*Process Data for getData(   )*/
	content[998] = '\n';
	content[999] = '\n';

	content[2000] = '\0';
	int prev_index = 0;
	int char_count = 0;
	char ch = '\0';
	for (int i = 0; i < 2000; i++)
	{
		// printf( "%c"  ,content[i]   ) ;

		if (content[i] == ' ')
		{
			char buff[500];
			strncat(buff, &content[prev_index], char_count);
			strncat(buff, &ch, 1);
			printf("%s\n", buff);
			sendmsg(buff);
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
