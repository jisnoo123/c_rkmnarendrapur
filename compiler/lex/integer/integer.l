%{
#include <stdio.h>
%}

%%
[+-]?[0-9]+        {printf("Valid floating point number");}
.+                 {printf("Invalid floating point number");}
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