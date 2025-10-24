#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* insertNode(struct node* list,int ele)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=ele;
    p->link=NULL;
    if(list==NULL)
    {
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

int isIdentical(struct node* list1,struct node* list2)
{
    struct node* temp1=list1;
    struct node* temp2=list2;

    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->data!=temp2->data)
        {
            return 0;
        }
        temp1=temp1->link;
        temp2=temp2->link;
    }

    if((temp1==NULL&&temp2!=NULL)||temp2==NULL&&temp1!=NULL){
        return 0;
    }

    return 1;
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
    struct node* list1=NULL;
    struct node* list2=NULL;

    list1=insertNode(list1,1);
    list1=insertNode(list1,2);
    list1=insertNode(list1,3);
    list1=insertNode(list1,4);

    //list2=insertNode(list2,1);
    //list2=insertNode(list2,2);
   // list2=insertNode(list2,3);
    //list2=insertNode(list2,4);

    if(isIdentical(list1,list2)==1)
    {
        printf("identical");
    }

    else{
        printf("Not identical");
    }
    return 0;
}