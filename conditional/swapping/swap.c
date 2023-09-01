//swapping the values in two variables
#include <stdio.h>
int main(){
	int a , b ,c;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	printf("\n Now a=%d and b=%d",a,b);
	//Third vairable is c
	c=a;
	a=b;
	b=c;
	printf("\nAfter swapping a=%d and b=%d",a,b);
}
