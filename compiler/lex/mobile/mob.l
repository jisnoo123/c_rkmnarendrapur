%{
#include <stdio.h>
%}

%%
\+?[1-9]{0,2}" "?[1-9][0-9]{9}    {printf("\n%s is a valid mobile number", yytext);}
.+                                {printf("Invalid mobile number");}
%%

int main(){
    int ch;
    printf("Enter the string: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}