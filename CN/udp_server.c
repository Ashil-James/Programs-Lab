#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("format not supported");
		return 0;
	}
	char buffer[1024];
	struct sockaddr_in server, client;
	int client_len = sizeof(client);
	int sockfd;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	
	if(bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0){
		printf("Error");
		return 0;
	}	
	
	printf("Server waiting");
	int n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&client, (socklen_t*)&client_len);
	buffer[n] = '\0';
	
	printf("got a datagram: %s\n", buffer);
	return 0;
}


