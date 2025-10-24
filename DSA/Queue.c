#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int queue[SIZE];
int front=-1;
int rear=-1;

void enQueue(int ele,int n){
    if(rear==n-1)
    {
        printf("Queue is full!\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=ele;
    printf("%d was enQueued\n",ele);
}

int deQueue(int n)
{
    if(front==-1){
        printf("Queue is Empty!\n");
        return -1;
    }

    int deqEle=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else {
        front++;
    }
    printf("%d was deQueued\n",deqEle);
    return deqEle;
}

void display(int n) {
    int i;
    if (front == -1 || front > rear) {
        printf("_ _ _ _ _\n");
        return;
    } else {
        printf("\nThe Elements in Linear Queue: \n");
        for (i = 0; i < n; i++) {
            if (i >= front && i <= rear) {
                printf("%d ", queue[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n\n");
    }
}


int main()
{
    int n;
    int ch;
    int element;
    int ele;

    printf("Enter the size of Queue: ");
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