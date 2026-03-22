#include<stdio.h>
#include<stdlib.h>


void stopnwait(){
    int w = 1;
    int f, frames[50];

    printf("Enter the number of frames to transmit: ");
    scanf("%d", &f);

    printf("Enter the integer values for frames: ");
    for(int i=1; i<=f; i++){
        scanf("%d", &frames[i]);
    }

    printf("\n---Transmission Starts---\n");
    for(int i=1; i<=f; i++){
        printf("Sending Frame %d (Value: %d)\n", i, frames[i]);
        printf("--> Waiting for Acknowledgement...\n");
        printf("<-- Acknowledgement recieved for Frame %d\n\n",i);
    }
    printf("---All frames transmitted successfuly ---\n");
}

void slrp(){
    int windowsize, sent = 0, ack;

    printf("Enter the window size: ");
    scanf("%d", &windowsize);

    for(int i=0; i<windowsize; i++)
    {
        printf("Frame %d has been transmitted..\n", sent);
        sent++;
    }
    printf("\n Enter the framenumber that was LOST/CORRUPTED: ");
    scanf("%d", &ack);

    printf("\n Resending Only Frame %d...\n", ack);
    printf("Frame %d has been re-transmitted..\n", ack);
}

void gobackn(){
    int windowsize, sent = 0, ack;
    printf("Enter the windowsize: ");
    scanf("%d",&windowsize);

    while(1){
        for(int i=0; i<windowsize; i++){
            printf("Frame %d has been transmitted...\n", sent);
            sent++;

            if(sent == windowsize) 
                break;   
        }
        printf("Enter the last Acknowledgement recieved: ");
        scanf("%d", &ack);

        if(ack == windowsize){
            printf("All Frames transmitted successfully....\n");
            break;
        } else{
            printf("\n Error detected! Retransmitting starting from Frame %d...\n", ack);
            sent = ack;
        }
    }
}

int main(){
    int n;
    char ans;
    do
    {
        printf("\n\nSliding Window Protocols Simulation:\n");
        printf("1. Stop-and-Wait ARQ\n");
        printf("2. Go-Back-N ARQ\n");
        printf("3. Selective Repeat ARQ\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1: stopnwait(); break;
            case 2: gobackn(); break;
            case 3: slrp(); break;
            case 4: exit(0);
            default: printf("Invalid Option. Please try again.\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ans); 

    } while(ans == 'y' || ans == 'Y');

    return 0;
}