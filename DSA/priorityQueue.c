#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int front=-1;
int rear=-1;

struct PriorityQueue{
    int element;
    int priority;
}pq[MAX];

void sortByPriority()
{
    for(int i=front;i<rear;i++)
    {
        for(int j=i+1;j<=rear;j++)
        {
            if(pq[i].priority>pq[j].priority)
            {
                struct PriorityQueue temp=pq[i];
                pq[i]=pq[j];
                pq[j]=temp;
            }
        }
    }
}

void enQueue(int ele,int prio,int n)
{
    if(rear==n-1)
    {
        printf("Priority-Queue Is Full!\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    pq[rear].element=ele;
    pq[rear].priority=prio;
    sortByPriority();
    printf("Enqueued element: %d with Priority: %d\n", ele, prio);
}

void deQueue()
{
    if(front==-1)
    {
        printf("Priority-Queue is Empty!\n");
        return;
    }

    int deqele=pq[front].element;
    int deqprio=pq[front].priority;
    if(front==rear)
    {
        front=-1;
        rear=-1;
        printf("Dequeued element: %d with Priority: %d\n", deqele, deqprio);
        return;
    }
    printf("Dequeued element: %d with Priority: %d\n", deqele, deqprio);
    front++;
}

void display()
{
    if(front==-1)
    {
        printf("Priority-Queue is Empty\n");
        return;
    }

    printf("Priority Queue: \n");
    for (int i = front; i <= rear; i++) {
    printf("Element: %d Priority: %d\n", pq[i].element, pq[i].priority);
    }
}

int main() {
    int ch;
    int e;
    int p;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while (1) {
        printf("Enter the choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter The Element and Priority: ");
                scanf("%d%d", &e, &p);
                enQueue(e, p, n);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}