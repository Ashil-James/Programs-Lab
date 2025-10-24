#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MAXSIZE 100
int resultStack[MAXSIZE];
int resultTop=-1;

void push(int value)
{
    if(resultTop==MAXSIZE-1)
    {
        printf("StackOverflow!!");
        exit(0);
    }
    resultStack[++resultTop]=value;
}

int pop(){
    if(resultTop==-1)
    {
        printf("StackUnderFlow!!");
        exit(0);
    }
    return resultStack[resultTop--];
}

int evaluate(char ch,int a,int b)
{
    switch(ch)
    {
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
        case '^': return(int) pow(b,a);
        default: return 0;
    }
}

int main()
{
    char postfix[100];
    printf("Enter the postfix expression ");
    scanf("%s", postfix);

    int values[52]={0};
    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalpha(postfix[i]))
        {
            if(islower(postfix[i])){
                printf("Enter the value of %c",postfix[i]);
                scanf("%d",&values[postfix[i]-'a']);
            }
            else{
                printf("Enter the value of %c",postfix[i]);
                scanf("%d",&values[postfix[i]-'A'+26]);
            }
        }
    }

    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalpha(postfix[i]))
        {
            if(islower(postfix[i])){
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
    printf("Result:%d \n",pop());
}