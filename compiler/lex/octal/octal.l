%{
#include <stdio.h>
%}

%%
[0-7]+                          {printf("Valid octal number");}
.+                              {printf("Invalid octal number");}
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