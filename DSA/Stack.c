#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

int stack[MAXSIZE];
int top=-1;

void push(int item){
    if(top==MAXSIZE-1){
        printf("Stack Overflow!");
        return;
    }
    stack[++top]=item;
}

int pop(){
    if(top==-1)
    {
        printf("UnderFlow!!");
        return -1;
    }

    return stack[top--];
}

void display()
{
    if(top==-1)
    {
        printf("Stack is Empty!!");
        return;
    }

    for(int i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}

int main()
{
    int ch,data;
    int element;
    while(1)
    {
        printf("Enter your choice");
        printf("1. push \n 2. pop \n 3. Display");

        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                printf("Enter data ");
                scanf("%d",&data);
                push(data);
                break;
        
        case 2: 
                element=pop();
                printf("%d was poped ",element);
                break;

        case 3: 
                display();
                break;
        default:
                printf("Invalid Input!! ");
            break;
        }
    }
    return 0;
}