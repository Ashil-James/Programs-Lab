#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){
	struct sockaddr_in server, client;
	socklen_t clilen = sizeof(client);
	int recv_bytes, sent_bytes;
	int n;
	int limit;
	int fibnum;
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("Enter the limit");
	scanf("%d", &limit);
	sent_bytes = sendto(sockfd, &limit, sizeof(limit),0, (struct sockaddr*)&server, sizeof(server));
	
	printf("Fibonacci Series: ");
	for(int i=0; i<limit; i++){
		recv_bytes = recvfrom(sockfd, &fibnum, sizeof(fibnum), 0, (struct sockaddr*)&client, &clilen);
		printf("%d ",fibnum);
	}
	
}
