%{
#include "y.tab.h"
%}

%%
[0-9]+ {return NUMBER;}
[+/*()-] {return yytext[0];}
[ \t\n] ;
. {return yytext[0];}
%%

int yywrap() {
	return 1;
}


