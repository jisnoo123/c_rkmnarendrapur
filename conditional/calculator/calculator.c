//Calculator using switch case
#include<stdio.h>
int main(){
	char c; int a , b ,res;
	printf("Enter an operator +, -, / or * :");
	scanf("%c",&c);
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	switch (c){
		case '+':
			res=a+b;
			printf("%d",res);
			break;
		case '-':
			res=a-b;
			printf("%d",res);
			break;
		case '*':
			res=a*b;
			printf("%d",res);
			break;
		case '/':
			res=a/b;
			printf("%d",res);
			break;
		default:
			printf("Wrong input");
	}
}
