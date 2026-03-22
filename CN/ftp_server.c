#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main() {
	FILE *fp;
	int sd, newsd, port, n, bind_status;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen;
	char rcv[BUFFER_SIZE], fileread[BUFFER_SIZE];
	int reuse = 1;
	
	printf("Enter the port address: ");
	scanf("%d", &port);
	
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0){
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	printf("socekt created");
	
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	
	bind_status = bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr) );
	if(bind_status < 0){
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Binded sucessfully.\n");
	
	listen(sd, 5);
	printf("Server is listening on port %d...\n", port);
	
	clilen = sizeof(cliaddr);
	newsd = accept(sd, (struct sockaddr*)&cliaddr, &clilen);
	
	if(newsd < 0 ){
		perror("Accept Failed");
		exit(EXIT_FAILURE);
	}	
	printf("Connection Accepted...\n");
	
	n = recv(newsd, rcv, BUFFER_SIZE - 1, 0);
	if(n < 0){
		perror("Recieve Failed");
		close(newsd);
		close(sd);
		return 1;
	}
	rcv[n] = '\0';
	
	if(n > 0 && rcv[n - 1] == '\n'){
		rcv[n-1] = '\0';
	}
	
	printf("Client request file: %s\n", rcv);
	
	fp = fopen(rcv, "rb");
	
	if(fp == NULL){
		printf("File not Found\n");
		send(newsd, "NONE", 4, 0);
		close(newsd);
	} else {
		int bytes_read; 
		while((bytes_read = fread(fileread, 1, sizeof(fileread), fp)) > 0) {
			if(send(newsd, fileread, bytes_read, 0) < 0){
				perror("Error sending file");
				break;
			} 
		}
		printf("File transfer completed...\n");
		fclose(fp);
		close(newsd);
	}
	
	close(sd);
	return 0;
}
