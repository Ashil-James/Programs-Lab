#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check if a character is an opening bracket
int isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if a character is a closing bracket
int isClosing(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to check if two brackets are matching
int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if the character is an operand (a number or variable)
int isOperand(char c) {
    return isdigit(c) || isalpha(c);
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if the expression is valid
int isValidExpression(char *expr) {
    int prevCharOperand = 0; // 1 if the previous character was an operand
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Check for parentheses validity
        if (isOpening(c)) {
            push(c);
        } else if (isClosing(c)) {
            if (top == -1 || !isMatching(pop(), c)) {
                return 0; // Invalid if unmatched parentheses
            }
        }
        
        // Validate operator placement: operators should be between operands
        if (isOperator(c)) {
            if (prevCharOperand == 0) {
                if(isClosing(prevCharOperand)&&isOperand(expr[i+1]))
                {
                    continue;
                }
                else{
                    return 0;
                }
            }
            prevCharOperand = 0; // After an operator, expect an operand
        }
        // Validate operand placement: operands should follow operators
        else if (isOperand(c)) {
            prevCharOperand = 1; // After an operand, expect an operator or closing parenthesis
        } else {
            return 0; // Invalid character
        }
    }

    // If stack is empty (balanced parentheses) and ends with an operand
    return (top == -1 && prevCharOperand == 1);
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isValidExpression(expression)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is invalid.\n");
    }

    return 0;
}
