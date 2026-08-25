%{
    #include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z_0-9]*  {printf("%s is a valid identifier ", yytext);}
.+   {printf("%s is not a valid identifier", yytext);}
%%

int yywrap(){
    return 0;
}

int main(){
    printf("Enter an identifier:");
    yylex();
    return 0;
}