bison -d $1.y
flex $1.l
gcc $1.tab.c lex.yy.c -o $1
./$1
