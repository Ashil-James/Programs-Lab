#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

#define PORT 8080

int main(int argc, char const* argv){
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char* hello = "HELLO FROM CLIENT";
	char buffer[1024] = {0};
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket error");
		exit(EXIT_FAILURE);
	}	
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
		printf("Invalid address");
		return -1;
	}
	
	if(connect(sock,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
		perror("Connection falied");
		exit(EXIT_FAILURE);
	}
	
	send(sock, hello, strlen(hello), 0);
	printf("Hello Message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer);
	return 0;
}
