%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
11[01]*11|111|11	{printf("ACCEPTED\n");}
[01]+			{printf("Rejected");}
[ \t\n]+ 		;
.			{printf("INvalid Input");}
%%

int main() {
	printf("Enter the string: \n");
	yylex();
	return 0;
}

int yywrap() {
	return 1;
}
