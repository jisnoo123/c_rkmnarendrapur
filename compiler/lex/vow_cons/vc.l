%{
#include <stdio.h>
int cons = 0, vow = 0;
%}

%%
[aeiouAEIOU]	{vow++;}
[A-Za-z]	{cons++;}
%%

int main(){
	printf("Enter string: ");
	yylex();
	printf("Vowels: %d, Consonants: %d", vow, cons);
}

int yywrap(){
	return 1;
}
