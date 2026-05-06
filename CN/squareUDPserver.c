#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

#define PORT 8080

int main() {
	
	struct sockaddr_in server, client;
	socklen_t clilen = sizeof(client);
	char buffer[1024];
	char result[1024];
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("Socket created successfuly...\n");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	int bind_status = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Binded Successfuly...\n");
	
	int recv_bytes = recvfrom(sockfd, buffer, sizeof(buffer),0, (struct sockaddr*)&client, &clilen);
	buffer[recv_bytes] = '\0';
	printf("Number recieved successfuly..\n");
	printf("The number is : %d", atoi(buffer));
	
	int num = atoi(buffer);
	int square = num * num;
	printf("Square Computed Successfuly..\n");
	printf("Square is: %d\n",square);
	
	sprintf(result, "%d", square);
	sendto(sockfd, result, strlen(result), 0,(struct sockaddr*)&client, sizeof(client));
	printf("Square Sent...\n");
}
