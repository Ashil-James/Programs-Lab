#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*head=NULL;

void insertNode(int data)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    if(head==NULL)
    {
        head=p; 
        return;
    }

    struct node* temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=p;
}

struct node* reverse(struct node* Head)
{
    struct node* curr=Head;
    struct node* prev=NULL;
    struct node* next=NULL;

    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;

        prev=curr;
        curr=next;
    }

    return prev;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->link != NULL) {
            printf("->");
        }
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);

    struct node* rev=NULL;
    rev=reverse(head);

    display(head);
    display(rev);

    return 0;
}