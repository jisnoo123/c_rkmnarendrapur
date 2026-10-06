%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *);
%}

%token ID NUM

%%
start: expr '\n' {printf("Valid expression");};
    
expr: expr '+' term
    | term;

term: term '*' factor
    | factor;

factor: '(' expr ')'
      | ID
      | NUM;

%%

void yyerror(const char *s){
	printf("Invalid\n");
}

int main(){
	printf("Enter valid expression:\n");
	yyparse();
	return 0;
}
