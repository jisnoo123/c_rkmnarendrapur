bison -d $1.y
flex $1.l
gcc lex.yy.c $1.tab.c -o $1
./$1
