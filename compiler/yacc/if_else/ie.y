%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(const char*);
%}

%token IF ELSE NUM ID DB_EQ LE GE

%%
stmt: IF '(' rexpn ')' '{' stmt '}' {printf("Valid");}
    | IF'(' rexpn ')' '{' stmt '}' ELSE '{' stmt '}'    {printf("Valid");}
    | assignment    {printf("Valid");}
    ;

rexpn: rexpn relop rexpn    {printf("rexpn 1");}
    |  ID                   {printf("rexpn 2");}
    | NUM                   {printf("rexpn 3");}
    ;

relop: '>'  {printf("relop 1");}
    |'<'    {printf("relop 2");}
    |LE     {printf("relop 3");}
    |GE     {printf("relop 4");}
    |DB_EQ  {printf("relop 5");};

assignment: ID '=' assignment {printf("A1");}
        | NUM  {printf("A2");}
        | ID   {printf("A3");}
        ;
%%

void yyerror(const char *s){
    printf("Invalid");
}

int main(){
    printf("Enter valid if else statement:");
    yyparse();
    return 0;
}