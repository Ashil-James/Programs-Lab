#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* front=NULL;
struct Node* rear=NULL;
struct Node* newNode;

void enQueue(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=newNode;
        return;
    }
    rear->link=newNode;
    rear=newNode;
}

void dequeue(){
    struct Node* temp;

    if(front==NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }
    temp=front;
    front=front->link;

    if(front==NULL)
    {
        rear=NULL;
    }    
    free(temp);
}

void printList()
{
    struct Node* temp = front;

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    enQueue(10);
    enQueue(20);
    printList();
    return 0;
}