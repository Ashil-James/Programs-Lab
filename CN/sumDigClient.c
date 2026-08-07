#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 8080

int main(){
	struct sockaddr_in server, client;
	int n;
	char num[1024];
	char buffer[1024];
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket Created Successfuly...\n");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int connection_stat = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Connected Successfuly..\n");
	
	printf("Enter the number to sent to the server: ");
	scanf("%d", &n);
	sprintf(num, "%d", n);
	send(sockfd, num, strlen(num), 0);
	printf("Number sent to the server....\n");
	int bytes_read = read(sockfd, buffer, sizeof(buffer));
	buffer[bytes_read] = '\0';
	printf("The sum is %s: ",buffer);
	
}
