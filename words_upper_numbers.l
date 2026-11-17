%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int words = 0;
int upper = 0;
int lower = 0;
int numbers = 0;
int puncutations = 0;
%}

%%
[^ \t\n]+	{	
			words++;
			for(int i=0; yytext[i] != '\0'; i++) {
				char ch = yytext[i];
				if(isupper(ch)) {
					upper++;
				} else if(islower(ch)) {
					lower++;
				} else if(isdigit(ch)) {
					numbers++;
				} else if(strchr(";,:.", ch)) {
					puncutations++;
				}
			}	
		}
[ \t\n]+	;
%%

int main(){

	printf("Enter the text: \n");
	yylex();
	printf("Number of words: %d\n", words);
	printf("Number of uppercase letters:%d\n", upper);
	printf("Number of lowercase letters: %d\n", lower);
	printf("Number of puncutations: %d", puncutations);
	printf("Nmuber of digits: %d", numbers);
	return 0;
}

int yywrap() {
	return 1;
}
