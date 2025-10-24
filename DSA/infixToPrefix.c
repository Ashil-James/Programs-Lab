#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int precedence(char ch) {
    if (ch == '(')
        return 0;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;

    return 0;
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char infix[100], prefix[100];
    char t;
    int k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    printf("Prefix: ");

    char* exp = infix;
    while (*exp != '\0') {
        if (isalnum(*exp)) {
            prefix[k++] = *exp;  // Append operands to prefix
        }
        else if (*exp == '(') {
            push(*exp);
        }
        else if (*exp == ')') {
            while ((t = pop()) != '(') {
                prefix[k++] = t;
            }
        }
        else {
            while (precedence(stack[top]) > precedence(*exp)) {
                prefix[k++] = pop();
            }
            push(*exp);
        }
        exp++;
    }

    while (top != -1) {
        prefix[k++] = pop();
    }
    prefix[k] = '\0';

    // Step 3: Reverse the postfix result to get prefix
    reverse(prefix);

    printf("%s\n", prefix);
    return 0;
}
