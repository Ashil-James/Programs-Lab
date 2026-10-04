%{
#include <stdio.h>
int vowels = 0, consonants = 0, lines = 0, chars = 0, words = 0;
%}

%%
[^ \t\n]+   { 
                words++; 
                chars += yyleng;
                for (int i = 0; i < yyleng; i++) {
                    char c = yytext[i];
                    // Check if it's an alphabet letter
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                            vowels++;
                        } else {
                            consonants++;
                        }
                    }
                }
            }
\n          { lines++; chars++; }
[ \t]       { chars++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the text (Press Ctrl+D on Linux/Mac or Ctrl+Z on Windows to stop):\n");
    yylex();
    
    printf("\n--- Analysis Results ---\n");
    printf("Lines       : %d\n", lines);
    printf("Words       : %d\n", words);
    printf("Characters  : %d\n", chars);
    printf("Vowels      : %d\n", vowels);
    printf("Consonants  : %d\n", consonants);
    return 0;
}
