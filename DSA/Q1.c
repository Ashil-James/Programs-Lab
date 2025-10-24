#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int ID;
    char name[50];
    float salary;
    struct Node *prev;
    struct Node *next;

};
struct Node* head=NULL, *newNode;

void insertBeg(int data,char* name, float salary){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->ID=data;
    strcpy(newNode->name, name);
    newNode->salary=salary;
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

void insertAfterID(int data,int position,char* name, float salary)
{
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->ID=data;
    strcpy(newNode->name, name);
    newNode->salary=salary;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(position==1){
        insertBeg(data,name,salary);
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
        newNode->next->prev = newNode; 
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

void deleteByID(int position)
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

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", temp->ID, temp->name, temp->salary);
        temp = temp->next;
    }
}

int main()
{
    
}
