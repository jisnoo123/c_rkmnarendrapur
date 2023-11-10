#include <stdio.h>
void swap(int *p,int *q){
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
int main(){
	int a,b;
	printf("Enter two values a and b : ");
	scanf("%d%d",&a,&b);
	printf("Values before swap a=%d and b=%d",a,b);
	swap(&a,&b);
	printf("\nValues after swap a=%d and b=%d",a,b);
}
