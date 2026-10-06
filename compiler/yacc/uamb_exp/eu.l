%{
#include <stdio.h>
#include "eu.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9_]* 	{return ID;}
[0-9]+ 	{return NUM;}
"+" 	{return '+';}
"=" 	{return '=';}
"-" 	{return '-';}
"("	{return '(';}
")" 	{return ')';}
"*"	{return '*';} 	
[ \t] 	;
[\n] 	{return '\n';}
. 	{return yytext[0];}
%%

int yywrap(){
	return 1;
}
