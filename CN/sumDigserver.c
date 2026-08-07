#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 8080
int main(){
	struct sockaddr_in server, client;
	int opt = 1;
	char buffer[1024];
	socklen_t clilen = sizeof(client);
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket created...\n");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEADDR, &opt, sizeof(opt));
	
	int bind_status = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Bind Successful...\n");
	
	listen(sockfd, 5);
	printf("Server is listening...\n");
	int newsock = accept(sockfd, (struct sockaddr*)&client, &clilen);
	printf("Connection established..\n");
	int valread = read(newsock, buffer, 1024);
	printf("value read...\n");
	
	int num = atoi(buffer);
	int sum = 0;
	
	printf("Computing Value...\n");
	while(num > 0 ){
		int rem = num % 10;
		sum += rem;
		num = num / 10;
	}
	printf("Sum is %d: ",sum);
	char result[1024];
	sprintf(result, "%d", sum);
	
	send(newsock, result, strlen(result), 0);
	printf("Value sent to the client...\n");
}
