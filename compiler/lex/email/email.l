%{
#include <stdio.h>
%}

%%
[A-Za-z0-9]+@[a-z]+(.[a-z]+)+   {printf("Valid email");}
.+                              {printf("Invalid email");}
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