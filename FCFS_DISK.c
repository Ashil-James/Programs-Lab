//FCFS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int queue[100];
    int diskhead;
    int totHeadMov=0;
    int n;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");   
    scanf("%d", &diskhead);

    for(int i=0;i<n;i++)
    {
        printf("Disk Moves From %d to %d\n",diskhead,queue[i]); 
        totHeadMov+= abs(queue[i]-diskhead);
        diskhead=queue[i];
    }

    printf("Total Head Movement: %d\n", totHeadMov);
    return 0;
}