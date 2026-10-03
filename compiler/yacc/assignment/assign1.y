%{
#include <stdio.h>

int yylex(void);
void yyerror(const char *s);
%}

%token ID NUM

%%

statement:
      ID '=' expression '\n'
      {
          printf("Valid assignment statement\n");
      }
      ;

expression:
      ID
    | NUM
    | expression '+' expression
    | expression '-' expression
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid assignment statement\n");
}

int main()
{
    printf("Enter assignment statement: ");
    yyparse();
    return 0;
}