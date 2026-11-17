%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
00[01]*00|000|00	{printf("ACCEPTED\n");}
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
