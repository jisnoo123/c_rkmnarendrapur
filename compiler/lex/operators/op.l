%{
#include <stdio.h>
%}

%%
[+-/*^] {printf("%s is an arithmetic operator", yytext);}
[<>]    {printf("%s is a relational operator", yytext);}
"<=" {printf("%s is a rlational operator", yytext);}
">=" {printf("%s is a relational operator", yytext);}
"!" {printf("%s is a logical operator", yytext);}
"||" {printf("%s is a logical operator", yytext);}
"&&" {printf("%s is a logical operator", yytext);}
"=" {printf("%s is an assignment operator", yytext);}
.+   {printf("%s is an invalid operator", yytext);}
%%

int yywrap(){
    return 0;
}

int main(){
    printf("Enter valid operators:");
    yylex();
    return 0;
}