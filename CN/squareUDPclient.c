#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){
	struct sockaddr_in server, client;
	socklen_t clilen = sizeof(client);
	char buffer[1024];
	int num;
	char res[1024];
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("Socket Created Successfuly...\n");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("Enter the number to send to server: ");
	scanf("%d", &num);
	
	sprintf(buffer,"%d",num);
	sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&server, sizeof(server));
	printf("Number sent to server..\n");
	
	int recv_bytes = recvfrom(sockfd, res, sizeof(res), 0, (struct sockaddr*)&client, &clilen);
	res[recv_bytes] = '\0';
	
	int ans = atoi(res);
	printf("Square: %d", ans);
}
