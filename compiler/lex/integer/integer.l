%{
#include <stdio.h>
%}

%%
[+-]?[0-9]+        {printf("Valid integer");}
.+                 {printf("Invalid integer");}
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