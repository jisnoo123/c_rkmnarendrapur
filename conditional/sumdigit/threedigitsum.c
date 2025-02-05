//Finding sum of digits of a 3 digit number using if else
#include <stdio.h>
int main(){
	int n,c=3,s=0;
	//c is a counter
	printf("enter a 3 digit number: ");
	scanf("%d",&n);
	printf("You have given the input: %d",n);
	if(c!=0){
		s=s+(n%10);n=n/10;c--;
	}
	if(c!=0){
		s=s+(n%10);c--;n=n/10;
	}
	if(c!=0){
		s=s+(n%10);c--;n=n/10;
	}
	if(c==0){
		printf("\n Sum of digits: %d",s);
	}
}
