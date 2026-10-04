%{
#include<stdio.h>
int words = 0;
int vowels = 0;
int consonants = 0;
int characters = 0;
int lines = 0;
int in_word = 0;
%}

%%
[aeiouAEIOU] {vowels++; characters++; if(!in_word){words++; in_word=1;}}
[a-zA-Z] {consonants++; characters++; if(!in_word){words++; in_word=1;}}
[ \t]+ {characters+=yyleng; in_word=0;}
\n {lines++; characters++; in_word=0;}
. {characters++; if(!in_word){in_word=1; words++;}}
%%

int main()
{
    printf("Enter the text:\n");
    yylex();

    printf("\nVowels     = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Lines      = %d\n", lines);
    printf("Characters = %d\n", characters);
    printf("Words      = %d\n", words);

    return 0;
}

int yywrap()
{
    return 1;
}
