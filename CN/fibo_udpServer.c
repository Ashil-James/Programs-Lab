#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT 8080

int main(){
	struct sockaddr_in server, client;
	socklen_t clilen = sizeof(client);
	int send_bytes;
	int recv_bytes;
	int f = 0, s = 1;
	int n; //Another approach of directly passing n instead of passing a string 
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("Socket Created Successfuly...\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	int bind_status = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
	printf("Binded Successfuly...\n");
	
	recv_bytes = recvfrom(sockfd, &n, sizeof(n), 0, (struct sockaddr*)&client, &clilen);
	
	send_bytes = sendto(sockfd, &f, sizeof(f), 0, (struct sockaddr*)&client, sizeof(client));
	send_bytes = sendto(sockfd, &s, sizeof(s), 0, (struct sockaddr*)&client, sizeof(client));
	for(int i = 3; i<=n; i++){
		int t = f + s;
		send_bytes = sendto(sockfd, &t, sizeof(t), 0, (struct sockaddr*)&client, sizeof(client));
		f = s;
		s = t;
	}
	printf("fibonacci series sent...\n");
}
