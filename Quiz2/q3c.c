// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Driver code
int main()
{
	int socketfd;
	char buffer[MAXLINE];
	char *hello = "Hello from client";
	struct sockaddr_in servaddr;
	(socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0;

	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	printf("Server : %s\n", buffer);

	close(socketfd);
	return 0;
}
