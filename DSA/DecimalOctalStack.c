#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int ele)
{
    top++;
    stack[top]=ele;
}

int pop()
{
    if(top==-1)
    {
        return -1;

    }
    return stack[top--];
}

int main()
{
    int decimal;
    printf("Enter the decimal number: ");
    scanf("%d",&decimal);
    while(decimal>0)
    {
        push(decimal%8);
        decimal=decimal/8;
    }

    printf("Octal: ");
    while(top!=-1)
    {
        printf("%d",pop());
    }
    return 0;
}