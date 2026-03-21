#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Format not supported");
		return 0;
	}
	
	struct sockaddr_in server,client;
	int sockfd = 0;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = INADDR_ANY;
	
	char buffer[100];
	printf("Enter the message to send to the server: ");
	fgets(buffer, sizeof(buffer), stdin);
	
	int n = sendto(sockfd, buffer, sizeof(buffer) ,0,(struct sockaddr*)&server, sizeof(server));
	
	return 0;
}
