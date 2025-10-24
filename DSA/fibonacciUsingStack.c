#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;

void push(int* stack,int* top,int ele)
{
    *top=*top+1;
    stack[*top]=ele;   
}

int pop(int* stack, int* top)
{
    if(*top==-1){
        return -1;
    }
    return stack[(*top)--];
}

void generateFibonacci(int n){
    push(stack1,&top1,0);
    push(stack1,&top1,1);
    int count=2;
    while(count<n){
        int top=pop(stack1,&top1);
        int nextTop=pop(stack1,&top1);

        push(stack2,&top2,top);
        push(stack2,&top2,nextTop);

        int eval=top+nextTop;
        top=pop(stack2,&top2);
        nextTop=pop(stack2,&top2);

        push(stack1,&top1,top);
        push(stack1,&top1,nextTop);
        push(stack1,&top1,eval);

        count++;
    }
}

void printFibo()
{
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
    printf("\n");
}

int main()
{
    generateFibonacci(7);
    printFibo();
    return 0;
}