%{
#include <stdio.h>
%}

%%
(http(s)?:)?(www\.)?[a-zA-Z0-9_]+\.[a-zA-Z0-9_\.]+		{printf("%s is a url", yytext);}
.+								{printf("%s is not a valid url", yytext);}
%%

int main(){
	printf("Enter your string: ");
	yylex();
}

int yywrap(){
	return 1;
}
