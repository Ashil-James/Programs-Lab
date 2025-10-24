#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node* link;
};

struct node* insert(struct node* list,char ele)
{   
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=ele;
    p->link=NULL;

    if(list==NULL){
        return p;
    }

    struct node* temp=list;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }

    temp->link=p;

    return list;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
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

void isPalinrdomeSLL(struct node* head)
{
    struct node* copySLL=NULL;
    struct node* reversedSLL=NULL;
    struct node* temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        copySLL=insert(copySLL,temp->data);
        temp=temp->link;
    }
    display(head);
    reversedSLL=reverse(copySLL);
    display(reversedSLL);

    struct node* temp2=reversedSLL;
    temp=head;
    while(temp2!=NULL)
    {
        if(temp->data!=temp2->data)
        {
            flag=1;
            printf("Not Palindrome");
            break;
        }
        temp=temp->link;
        temp2=temp2->link;
    }
    if(flag==0)
    {
        printf("Palindrome");
    }
}



int main()
{
    char str[50];
    struct node* list=NULL;
    printf("Enter the string");
    scanf("%s",str);
    strlwr(str);
    for(int i=0;i<strlen(str);i++)
    {
        list=insert(list,str[i]);
    }

    isPalinrdomeSLL(list);
    return 0;
}