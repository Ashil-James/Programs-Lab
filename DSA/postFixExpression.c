#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    if(top==-1)
    {
        return '\0';
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

int main()
{
    char infix[100];
    char t;

    printf("Enter postfix expression: ");
    scanf("%s",infix);
    char *exp=infix;

    printf("Postfix: ");
    while(*exp!='\0')
    {
        if(isalnum(*exp)){
            printf("%c",*exp);
        }

        else if(*exp=='(')
        {
            push(*exp);
        }

        else if(*exp==')')
        {
            while((t=pop())!='(')
            {
                printf("%c",t);
            }
        }

        else{
            while(precedence(stack[top])>=precedence(*exp))
            {
                printf("%c",pop());
            }
            push(*exp);
        }
        exp++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}