%{
#include <stdio.h>
%}

%%
[01]+                           {printf("Valid binary number");}
.+                              {printf("Invalid binary number");}
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