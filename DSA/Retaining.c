#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*head=NULL;

void insert(int data){
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

void retain(int m, int n) {
    struct node* temp = head; 
    struct node* prev = NULL;

    while(temp!=NULL)
    {
        for(int i=1;i<=m&&temp!=NULL;i++)
        {
            prev=temp;
            temp=temp->link;
        }

        for(int j=1;j<=n&&temp!=NULL;j++)
        {
            struct node* toDelete=temp;
            temp=temp->link;
            free(toDelete);
        }

        prev->link=temp;
    }
}

void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        if(temp->link!=NULL)
            printf("%d->",temp->data);
        else
            printf("%d",temp->data);
        temp=temp->link;
    }
    
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    retain(1,1);
    display();
    return 0;
}