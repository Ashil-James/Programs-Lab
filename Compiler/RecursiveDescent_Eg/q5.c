// S -> (S)S | id

#include<stdio.h>
#include<stdlib.h>

char s[100];
int i = 0;

void S();
void error(){
    printf("Invalid String\n");
    exit(0);
}

void S() {
    if(s[i] == '(') {
        i++;
        S();
        if(s[i] == ')'){
            i++;
            S();
        } else {
            error();
        }
    } 

    else if(s[i] == 'i' && s[i + 1] == 'd') {
        i += 2;
    } 
    
    else {
        error();
    }
}

int main() {

    printf("Enter String: ");
    scanf("%s", s);

    S();

    if(s[i] == '\0') {
        printf("Accepted");
    } else {
        printf("Rejected");
    }
    return 0;
}