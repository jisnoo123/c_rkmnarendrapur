%{
    #include <stdio.h>
    #include "assign1.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]* {return ID;}
[0-9]+ {return NUM;}
"+" {return '+';}
"=" {return '=';}
"-" {return '-';}
[\t] ;
" " ;
"\n" {return '\n';}
. {return yytext[0];}
%%

int yywrap(){
    return 0;
}