#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int ch)
{
    stack[++top]=ch;
}

int pop()
{
    if(top==-1)
    {
        return 0;
    }
    return stack[top--];
}

int precedence(char ch)
{
    if(ch=='(')
        return 0;
    if(ch=='+'||ch=='-')
        return 1;
    if(ch=='*'||ch=='/')
        return 2;
    if(ch=='^')
        return 3;
    
    return 0;
}

int evaluate(char ch,int a,int b)
{
    switch(ch){
        case '+':
            return b+a;
        case '-':
            return b-a;
        case '*':
            return b*a;
        case '/':
            return b/a;
        case '^':
            return (int)pow(b,a);
        
        default:
            return 0;
    }
}

int main()
{
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s",postfix);

    int values[52]={0};
    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalpha(postfix[i]))
        {
            if(islower(postfix[i]))
            {
                printf("Enter value of %c: ",postfix[i]);
                scanf("%d",&values[postfix[i]-'a']);
            }
            else{
                 printf("Enter value of %c: ",postfix[i]);
                 scanf("%d",&values[postfix[i]-'A'+26]);
            }
        }
    }

    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalpha(postfix[i]))
        {
            if(islower(postfix[i]))
            {
                push(values[postfix[i]-'a']);
            }
            else{
                push(values[postfix[i]-'A'+26]);
            }
        }
        else{
            int op1=pop();
            int op2=pop();
            push(evaluate(postfix[i],op1,op2));
        }
    }
    printf("Result: %d",pop());
    return 0;
}

