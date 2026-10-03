%{
    #include <stdio.h>
    #include "ie1.tab.h"
%}

%%
if        {return IF;}
else      {return ELSE;}
"("       {return '(';}
")"       {return ')';}
"{"       {return '{';}
"}"       {return '}'; }
"="       {return '=';}
"<"       {return '<';}
">"       {return '>';}
"<="      {return LE;}
">="      {return GE;}
"=="      {return DB_EQ;}
[0-9]+    {return NUM;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
[\t] ;
\n {return '\n';}
. {return yytext[0];}
%%

int yywrap(){
    return 0;
}