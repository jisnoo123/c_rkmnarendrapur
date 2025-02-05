#include <stdio.h>
int main(){
	int a , b ,c;
	printf("Enter three numbers ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c){
		printf("\n %d is greatest",a);
	}
	else if(b>a && b>c){
		printf("\n %d is greatest",b);
	}
	else {
		printf("\n %d is greatest",c);
	}
}
