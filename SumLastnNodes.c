#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* insert(struct node* num,int ele)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=ele,
    p->link=NULL;
    if(num==NULL)
    {
        return p;
    }
    struct node* temp=num;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=p;
    return num;
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

struct node* reverse(struct node* head)
{
    struct node* curr=head;
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

int sumLastNodes(struct node* head,int n)
{
    struct node* copySLL=NULL;
    struct node* reversedSLL=NULL;
    struct node* temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        copySLL=insert(copySLL,temp->data);
        temp=temp->link;
    }
    display(head);
    reversedSLL=reverse(copySLL);
    display(reversedSLL);

    struct node* temp2=reversedSLL;
    for(int i=1;i<=n;i++)
    {
        sum=sum+temp2->data;
        temp2=temp2->link;
    }
    return sum;
}

int main()
{
    struct node* exp=NULL;
    exp=insert(exp,1);
    exp=insert(exp,2);
    exp=insert(exp,3);
    exp=insert(exp,4);
    exp=insert(exp,5);

    printf("%d",sumLastNodes(exp,2));

    return 0;
}