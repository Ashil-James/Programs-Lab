#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int circularQueue[SIZE];
int front=-1;
int rear=-1;

void enQueue(int ele,int n)
{
    if(front==rear+1||front==0&&rear==n-1)
    {
        printf("Circualr Queue Full!\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%n;
    circularQueue[rear]=ele;
    printf("%d was enQueued\n");
}

int deQueue(int n){
    if(front==-1)
    {
        printf("Circular Queue is Empty!!\n");
        return -1;
    }
    int deq=circularQueue[front];
    if(front == rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%n;
    }
    printf("%d was deQueued \n",deq);
    return deq;
}

void display(int n)
{
    if(front==-1)
    {
        printf("_ _ _ _ _ ");
        return;
    }
    printf("\nThe elements in circualrQueue: \n");
    for(int i=0;i<n;i++){
        if(i>=front&&i<=rear)
        {
            printf("%d ",circularQueue[i]);
        } 
        else if(front>rear&&(i>=front||i<=rear))
        {
            printf("%d ",circularQueue[i]);
        }
        else{
            printf("_ ");
        }
    }
    printf("\n");
}

int main()
{
    int n;
    int ch;
    int element;
    int ele;

    printf("Enter the size of Circular-Queue: ");
    scanf("%d",&n);
    while(1){
        printf("Enter your choice");
        printf("\nMenu\n");
        printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("Enter the element to enQueue: ");
                    scanf("%d",&element);
                    enQueue(element,n);
                    display(n);
                    break;
            case 2:
                    ele=deQueue(n);
                    display(n);
                    break;
            case 3:
                    display(n);
                    break;
            case 4:
                    exit(0);
                    break;
            
            default:
                    printf("Invalid Input!");
        }
    }
    return 0;
}