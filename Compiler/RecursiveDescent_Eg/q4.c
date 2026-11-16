// S -> 0S | 1S | 01
#include<stdio.h>
#include<stdlib.h>

char s[100];
int i = 0;

void S();

void error() {
    printf("Invalid String\n");
    exit(0);
}

void S() {

    if(s[i] == '0' && s[i+1] == '1') {
        i = i + 2;
    }

    else if(s[i] == '0' || s[i] == '1') {
        i++;
        S();
    }

    else {
        error();
    }
}

int main() {

    printf("Enter the string: ");
    scanf("%99s", s);

    S();

    if(s[i] == '\0') {
        printf("Accepted\n");
    }
    else {
        printf("Rejected\n");
    }

    return 0;
}
