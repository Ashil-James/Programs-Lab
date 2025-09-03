#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL, *newNode;

void insertBeg(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
        if(head==NULL)
        {
           newNode->next=NULL;
           head=newNode;
           return;
        }
    newNode->next=head;
    head=newNode;
    newNode->next->prev=newNode;
}

void insertEnd(int data)
{
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    if(head!=NULL)
    {
        struct Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    else{
        insertBeg(data);
    }
}

void insertPosition(int data,int position)
{
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(position==1){
        insertBeg(data);
        return;
    }
    struct Node* temp=head;
    for(int i=1;i<position-1&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Position exceeds Limit ");
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode; // Link the next node's prev to newNode
    }
}

void deleteBeg(){
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    if(temp->prev==NULL)
    {
        free(temp);
        head=NULL;
        return;
    }
    temp->prev->next=NULL;
    free(temp);
}

    void deletePosition(int position)
    {
        if(head==NULL){
            printf("List is Empty");
            return;
        }
        if(position==1){
            deleteBeg();
            return;
        }
        struct Node* temp=head;
        for(int i=1;i<position&&temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Position Exceeds Maximum Size");
            return;
        }
        if(temp->prev!=NULL){
            temp->prev->next=temp->next;
        }
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }
        free(temp);
    }
void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    insertEnd(10);
    display();
    return 0;
}