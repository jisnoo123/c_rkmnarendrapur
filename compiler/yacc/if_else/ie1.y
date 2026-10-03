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

rexpn: rexpn relop rexpn    
    |  ID                 
    | NUM                   
    ;

relop: '>' 
    |'<'    
    |LE     
    |GE     
    |DB_EQ  ;

assignment: ID '=' assignment 
        | NUM  
        | ID   
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