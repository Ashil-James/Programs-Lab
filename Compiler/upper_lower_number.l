%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int upper = 0;
int lower = 0;
int numbers = 0;
int words = 0;
%}

%%
[A-Z] 		{upper++;}
[a-z]		{lower++;}
[0-9]		{numbers++;}
%%

int main() {
	printf("Enter the input: \n");
	yylex();
	printf("Uppercase: %d\n", upper);
	printf("Lowercase: %d\n", lower);
	printf("Numbers: %d\n", numbers);
	return 0;
}

int yywrap() {
	return 1;
}
