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
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
    newNode->next->prev=newNode;
}
void insertEnd(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head!=NULL){
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

int isPalindrome()
{
    struct Node* temp=head;
    struct Node* left=head,*right=head;

    while(right->next!=NULL)
    {
        right=right->next;
    }

    while(left!=right && left->prev!=right)
    {
        if(left->data!=right->data)
        {
            return 0;
        }
        left=left->next;
        right=right->prev;
    }
    return 1;
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
    insertBeg(10);
    insertBeg(20);
    insertBeg(10);
    insertBeg(30);
    insertEnd(30);
    display();

    int isPalin=isPalindrome();
    if(isPalin==1)
    {
        printf("Palindrome");
    }
    else{
        printf("Not palindrome");
    }
    return 0;
}