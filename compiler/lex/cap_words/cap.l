%{
#include <stdio.h>
%}

%%
[A-Z][A-Za-z]+	{printf("\n%s is a captial letter word", yytext);}
.		{;}
%%

int main(){
	printf("Enter string: ");
	yylex();
}

int yywrap(){
	return 1;
}
