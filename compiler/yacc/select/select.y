%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *);
%}

%token SELECT ID NUM FROM WHERE GROUP_BY HAVING ORDER_BY ASC DESC AND OR EQ NEQ GT GE LT LE

%%
start : query '\n' {printf("Valid Condition!");}

query: select_clause from_clause where_clause group_by_clause order_clause having_clause '\n' {printf("Valid SELECT statement!");}
     ;

// Condition grammar

cond: scond
    | scond logop cond
    ;

logop: AND
     | OR
     ;

scond: inum
     | inum relop inum
     ;

inum: ID
    | NUM
    ;

relop: EQ
     | NEQ
     | GT
     | GE
     | LE
     | LT
     ;

// Condition grammar end

select_clause: SELECT attr_list
             | SELECT '*' 
             ;

attr_list: ID
         | ID ';' attr_list
         ;

from_clause: FROM attr_list
           ;

where_clause: WHERE cond
            |
            ;

group_by_clause: GROUP_BY ID having_clause
            |
            ;

having_clause: HAVING scond
             |
             ;

order_clause: ORDER_BY ID type
            |
            ;

type: ASC
    | DESC
    ;
%%

void yyerror(const char *s){
    printf("\nInvalid");
}

int main(){
    printf("Enter valid condition: ");
    yyparse();
    return 0;
}
