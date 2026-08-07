#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 8080

int main(){
	struct sockaddr_in server, client;
	socklen_t clilen = sizeof(client);
	int num1;
	int num2;
	int sum;
	char buffer[1024];
	int opt = 1;
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket created...\n");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT | SO_REUSEADDR, &opt, sizeof(opt));
	
	int bind_status = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Bind created...\n");
	
	listen(sockfd, 5);
	printf("Server is listening...\n");
	
	int newsock = accept(sockfd, (struct sockaddr*)&client, &clilen);
	int bytes_read1 = read(newsock, buffer, sizeof(buffer));
	num1 = atoi(buffer);
	int bytes_read2 = read(newsock, buffer, sizeof(buffer));
	num2 = atoi(buffer);
	
	sum = num1 + num2;
	sprintf(buffer,"%d",sum);
	send(newsock, buffer, strlen(buffer), 0);
	printf("Sum computed and sent to client...\n");
}
