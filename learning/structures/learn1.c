#include <stdio.h>
int main(){
	struct ex{
		int i;
		char c;
	};
	struct ex a , b;
	a.i=10;
	a.c='a';
	b.i=20;
	b.c='b';
	printf("%d %c",a.i,a.c);
	printf("\n%d %c",b.i,b.c);
}
