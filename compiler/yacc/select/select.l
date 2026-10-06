%{
#include <stdio.h>
#include "select.tab.h"
%}

%%
"SELECT"                {return SELECT;}
"FROM"                  {return FROM;}
"AND"                   {return AND;}
"OR"                    {return OR;}
"GROUP BY"              {return GROUP_BY;}
"HAVING"                {return HAVING;}
"ORDER BY"              {return ORDER_BY;}
"ASC"                   {return ASC;}
"DESC"                  {return DESC;}
[a-zA-Z][a-zA-Z0-9_]*   {return ID;}
[0-9]+                  {return NUM;}
">="                    {return GE;}
"<="                    {return LE;}
"<"                     {return LT;}
">"                     {return GT;}
"*"                     {return '*';}        
[ \t]                   ;
[\n]                    {return '\n';}
.                       {return yytext[0];}
%%

int yywrap(){
    return 1;
}
