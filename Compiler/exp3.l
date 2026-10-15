%{
#include<stdio.h>
int lines = 0;
int words = 0;
int characters = 0;
%}

%%
[ \t]+ {characters+=yyleng;}
\n 	{lines++; characters++;}
[^ \t\n]+ {words++; characters+=yyleng;}
%%

int main() {
	printf("Enter text: \n");
	yylex();
	
	printf("\nNumber of lines      : %d\n", lines);
    	printf("Number of words      : %d\n", words);
    	printf("Number of characters : %d\n", characters);
    	
	return 0;
}

int yywrap() {
	return 1;
}
