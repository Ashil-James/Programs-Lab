%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
0[01]*1|1[01]*0		{printf("ACCEPTED\n");}
[01]+			{printf("REJECTED\n");}
[ \t\n]+ 		;
.			{printf("Invalid Input\n");}
%%

int main() {
	printf("Enter the string: \n");
	yylex();
	return 0;
}

int yywrap() {
	return 1;
}
