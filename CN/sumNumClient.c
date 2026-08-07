#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){
	struct sockaddr_in server;
	int num1;
	int num2;
	char buffer[1024];
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int connection_status = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Connected to Server...\n");
	
	printf("Enter First number: ");
	scanf("%d", &num1);
	sprintf(buffer, "%d", num1);
	int n = send(sockfd, buffer, strlen(buffer), 0);
	
	printf("Enter Second Number: ");
	scanf("%d", &num2);
	sprintf(buffer, "%d", num2);
	int m = send(sockfd, buffer, strlen(buffer), 0);
	
	int recvbytes = read(sockfd, buffer, sizeof(buffer));
	buffer[recvbytes] = '\0';
	
	printf("The sum of the numbers are: %d", atoi(buffer));
	
	
}
