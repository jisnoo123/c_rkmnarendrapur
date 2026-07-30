%{
#include <stdio.h>
%}

%%
((0?[1-9])|([12][0-9])|(3[01]))\/((0?[1-9])|(1[012]))\/([0-9]{2,4})    {printf("Valid date");}
.+                                {printf("Invalid date");}
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