#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* head=NULL, *newNode;

void push(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
    newNode->link=head;
    head=newNode;
}

void pop(){
    if(head==NULL){
        printf("Stack is Empty!\n");
        return;
    }
    struct Node* temp=head;
    printf("Poped Element: %d\n",head->data);
    head=head->link;
    free(temp);
}

void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();

    return 0;
}