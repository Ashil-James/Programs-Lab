#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{

    int queue[100];
    int head;
    int n;
    int completed[20];
    int totHeadMov=0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &queue[i]);
        completed[i]=0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    for(int i=0;i<n;i++)
    {
        int min=INT_MAX;
        int minIndex=-1;

        for(int j=0;j<n;j++)
        {
            if(completed[j]==0)
            {
                int diff=abs(queue[j]-head);
                if(diff<min)
                {
                    min=diff;
                    minIndex=j;
                }
            }   
        }
        
        int currentReq=queue[minIndex];
        printf("Disk Moves From %d to %d\n",head,currentReq);
        completed[minIndex]=1;
        totHeadMov+=abs(currentReq-head);
        head=currentReq;

    }
    printf("Total Head Movement: %d\n", totHeadMov);
    
    return 0;
}