    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    #define MAXSIZE 100
    char stack[MAXSIZE];
    int top=-1;

    void push(char item){
        stack[++top]=item;
    }

    char pop(){
        if(top==-1)
        {
            printf("Stack Underflow!!\n");
            return '\0';
        }
        return stack[top--];
    }

    int precendence(char ch)
    {
        if(ch=='('){
            return 0;
        }
        else if(ch=='+'||ch=='-'){
            return 1;
        }
        else if(ch=='*'||ch=='/'){
            return 2;
        }
        else if(ch=='^'){
            return 3;
        }
        return 0;
    }

    int main()
    {
        char infix[100];
        char t;
        printf("Enter the infix expression: ");
        scanf("%s",infix);
        char *exp=infix;
        while(*exp!='\0')
        {
            if(isalnum(*exp))
            {
                printf("%c",*exp);
            }
            else if(*exp=='(')
            {
                push(*exp);
            }
            else if(*exp==')')
            {
                while((t=pop())!='('){
                    printf("%c",t);
                }
            }
            else{
                while(precendence(stack[top])>=precendence(*exp))
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