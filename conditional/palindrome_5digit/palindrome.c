#include <stdio.h>
int main(){
		int n,b,r=0,d;
		printf("Enter a five digit number: ");
		scanf("%d",&n);
		b=n;
		d=b%10;
		b/=10;
		r=(r*10)+d;
		d=b%10;
		b/=10;
		r=(r*10)+d;
		d=b%10;
		b/=10;
		r=(r*10)+d;
		d=b%10;
		b/=10;
		r=(r*10)+d;
		d=b%10;
		b/=10;
		r=(r*10)+d;
		if(r==n){
			printf("%d and %d are palindrome",n,r);
		}
		else{
			printf("%d and %d are not palindrome",n,r);
		}
}
