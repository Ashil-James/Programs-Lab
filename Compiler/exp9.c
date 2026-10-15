#include<stdio.h>
#include<stdlib.h>

char s[100];
int i = 0;

void E();
void E1();
void T();
void T1();
void F();

void error() {
    printf("Invalid String:\n");
    exit(0);
}

void E() {
    T();
    E1();
}

void E1() {
    if(s[i] == '+' || s[i] == '-') {
        i++;
        T();
        E1();
    }
}

void T() {
    F();
    T1();
}

void T1() {
    if(s[i] == '*' || s[i] == '/') {
        i++;
        F();
        T1();
    }
}

void F() {
    if(s[i] == 'i' && s[i + 1] == 'd') {
        i+=2;
    } else if(s[i] == '(') {
        i++;
        E();
        if(s[i] == ')'){
            i++;
        } else {
            error();
        }
    } else {
        error();
    }
}

int main() {
    printf("Enter String: ");
    scanf("%s", s);

    E();

    if(s[i] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Rejected");
    }
    return 0;
}
