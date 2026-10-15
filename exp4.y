%{
#include<stdio.h>
int yylex();
int yyerror(char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
expr : expr '+' expr
     | expr '-' expr
     | expr '*' expr
     | expr '/' expr
     | NUMBER
     | '('expr')'
     ;
%%

int main() {
	printf("Enter Arithmetic expression: ");
	if(yyparse() == 0) {
		printf("Valid Expression\n");
	}
	
	return 0;
}

int yyerror(char *s) {
	printf("Invalid Expression");

	return 0;
}
