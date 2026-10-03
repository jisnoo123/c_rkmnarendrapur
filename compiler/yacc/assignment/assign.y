%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(const char*);
%}

%token ID NUM

%%
stmt: ID '=' expr'\n' {printf("Valid");}
expr: ID
    | NUM
    |expr '+' expr
    |expr '-' expr;
%%

void yyerror(const char *s){
    printf("Invalid");
}

int main(){
    printf("Enter valid assignment statement:");
    yyparse();
    return 0;
}