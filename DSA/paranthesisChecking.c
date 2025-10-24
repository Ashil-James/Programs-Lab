#include<stdio.h>
#include<stdlib.h>

#define MAX 100
char stack[MAX];
int top=-1;
    
void push(char ele)
{
    stack[++top]=ele;
}

char pop()
{
    if(top==-1)
    {
        return '\0';
    }
    return stack[top--];
}

int isMatching(char* exp)
{
    while(*exp!='\0'){
        char opening=*exp;
        if(opening=='('||opening=='{'||opening=='[')
            push(opening);
        
        else if(opening==')'||opening=='}'||opening==']')
        {
            char closing=pop();
            if(opening=='('&&closing!=')'||
               opening=='{'&&closing!='}'||
               opening =='['&& closing!=']'){
                return 0;
               }
        }
        exp++;
    }
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char ex[100];
    printf("Enter the expression: ");

    scanf("%s",ex);
    int matching=isMatching(ex);
    if(matching==1)
    {
        printf("Matching");
    }
    else{
        printf("not matchnig");
    }
    return 0;
}