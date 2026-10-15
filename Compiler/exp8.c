#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char p[10][10];
int n;

void first(char c) {
    if(!isupper(c)) {
        printf("%c", c);
        return;
    }

    for(int i=0 ;i<n; i++) {
        if(p[i][0] == c) {
            if(p[i][2] == '#') {
                printf("#");
            } else {
                first(p[i][2]);
            }
        }
    }
}


void follow(char c) {
    if(c == p[0][0]) {
        printf("$");
    }

    for(int i=0; i<n; i++) {
        for(int j=2; p[i][j] != '\0'; j++) {
            if(p[i][j] == c) {
                if(p[i][j + 1] != '\0') {
                    first(p[i][j + 1]);
                } 
                else if(p[i][0] != c) {
                    follow(p[i][0]);
                }
            }
        }
    }
}

int main() {
    char c;
    int i;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%s", p[i]);
    }

    printf("\nFIRST: \n");
    for(int i=0; i<n; i++) {
        c = p[i][0];
        printf("First(%c) = {", c);
        first(c);
        printf("}\n");
    }

    
    printf("\nFollow: \n");
    for(int i=0; i<n; i++) {
        c = p[i][0];
        printf("Follow(%c) = {", c);
        follow(c);
        printf("}\n");
    }
}
