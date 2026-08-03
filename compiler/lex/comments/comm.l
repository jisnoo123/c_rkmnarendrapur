%{
#include <stdio.h>
int sl=0, ml=0;
%}

%%
\/\/.+[\n\Z]				{sl++;}
\/\*[A-Za-z0-9_' '",\.\(\)\\\n]+\*\/	{ml++;}
%%

int main(int argc, char* argv[]){
	if(argc == 2){
		yyin = fopen(argv[1], "r");
	}
	else{
		printf("Enter input:");
		yyin = stdin;
	}
	yylex();
	printf("Single line: %d, Multi line: %d", sl, ml);
}

int yywrap(){
	return 1;
}
