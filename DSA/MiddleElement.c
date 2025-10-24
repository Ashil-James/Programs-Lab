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

int middleElement(struct node* list)
{
    struct node* temp=list;
    int c=0;
    int mid=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->link;
    }
    temp=list;
    if(c%2==0)
    {
        mid=c/2;
    }
    else{
        mid=(c+1)/2;
    }

    for(int i=1;i<mid;i++)
    {
        temp=temp->link;
    }
    return temp->data;
}

int main()
{
    struct node* exp=NULL;
    exp=insert(exp,1);
    exp=insert(exp,2);
    exp=insert(exp,3);
    exp=insert(exp,4);
    exp=insert(exp,5);

    printf("%d",middleElement(exp));

    return 0;
}