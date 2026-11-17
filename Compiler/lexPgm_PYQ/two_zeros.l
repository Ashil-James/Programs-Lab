%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
[01]*0[01]*0[01]*	{printf("Accepted\n");}
[01]+			{printf("Rejected\n");}
[ \t\n]+ 		;
.			{printf("INvalid Input\n");}
%%

int main() {
	printf("Enter the string: \n");
	yylex();
	return 0;
}

int yywrap() {
	return 1;
}
