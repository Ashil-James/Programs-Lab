#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(){
	FILE* fp;
	struct sockaddr_in servaddr;
	char name[100], fname[100];	
	int csd, n, port;
	char rcvg[BUFFER_SIZE];
	
	printf("Enter the port");
	scanf("%d", &port);
	
	csd = socket(AF_INET, SOCK_STREAM, 0);
	if(csd < 0) {
		perror("Socket Failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Socket Created");
	
	memset(&servaddr, 0, sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(connect(csd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
		perror("Connection Failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Connected to Server...\n");
	
	printf("Enter the exsisting file on sever: ");
	scanf("%s", name);
	
	printf("Enter the new filename to save as: ");
	scanf("%s", fname);
	
	send(csd, name, strlen(name), 0);
	
	fp = fopen(fname, "wb");
	
	if(fp == NULL){
		printf("Error Opening the file");
		return 1;
	}
	
	printf("Recieveing File: ");
	while(1){
		int bytes_recieved = recv(csd, rcvg, BUFFER_SIZE, 0);
		
		if(bytes_recieved < 0){
			perror("Error reading file");
			break;
		}
		
		if(bytes_recieved == 0){
			printf("Server connection closed, Transfer complete..\n");
			break;
		}
		
		if(bytes_recieved == 5 && strncmp(rcvg, "error", 5) == 0){
			printf("File not found on server...\n");
			fclose(fp);
			remove(fname);
			close(csd);
			return 0;
		}
		fwrite(rcvg, 1, bytes_recieved, fp);
		
	}
	fclose(fp);
	close(csd);
	printf("File saved as %s\n", fname);
	
	return 0;
}
