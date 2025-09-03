#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int dequeue[SIZE];
int front=-1;
int rear=-1;

void insertRear(int n,int ele)
{
    if(rear==n-1){
        printf("DeQueue is Empty!\n");
        return;
    }

    if(front==-1){
        front=0;
    }

    rear++;
    dequeue[rear]=ele;
    printf("%d was enQueued at Rear\n",ele);
}

int deleteFront(int n)
{
    if(front==-1)
    {
        printf("DeQueue is Empty!\n");
        return -1;
    }

    int deqel=dequeue[front];
    if(front == rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    printf("%d was dequeued from front\n",deqel);
    return deqel;
}

void insertFront(int n,int ele){
    if(front==-1)
    {
        front=0;
        rear=0;
        dequeue[front]=ele;
        printf("%d was enQueued at front\n",ele);
        return;
    }

    else if(front>0)
    {
        front=front-1;
        dequeue[front]=ele;
        printf("%d was enQueued at Rear\n",ele);
        return;
    }
    else{
        printf("insertion not possible\n");
        return;
    }
}

int deleteRear(int n){
    if(rear==-1)
    {
        printf("DeQueue is Empty!\n");
        return -1;
    }
    
    int deqel=dequeue[rear];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        rear--;
    }
    printf("%d was deQueued from Rear\n",deqel);
    return deqel;
}

void display(int n) {
    if (front == -1) {
        printf("No elements in deque\n");
        return;
    }
    printf("Current Deque Elements: \n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", dequeue[i]);
        }
    } else {
        for (int i = front; i < n; i++) {
            printf("%d\t", dequeue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d\t", dequeue[i]);
        }
    }
    printf("\n");
}


void main() {
    int n, ch, ele;
    printf("Enter the size of deque: ");
    scanf("%d", &n);
    while (1) {
        printf("Enter the choice \n");
        printf("1. Insert at Front\t2. Insert at Rear\t3. Delete from Front\t4. Delete from Rear\t5. Display elements in deque\t6. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &ele);
                insertFront(n,ele);
                display(n);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &ele);
                insertRear(n, ele);
                display(n);
                break;
            case 3:
                deleteFront(n);
                display(n);
                break;
            case 4:
                deleteRear(n);
                display(n);
                break;
            case 5:
                printf("Elements in deque are: ");
                display(n);
                printf("\n");
                break;
            case 6:
                printf("Program exited successfully!\n");
                exit(0);
        }
    }
}