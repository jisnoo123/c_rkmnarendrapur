//To find the real roots of a quadratic equation
#include <stdio.h> 
#include<math.h>
int main(){
	int a , b , c,d;
	float r1,r2;
	printf("\nEnter a , b and c of the quadratic equation ax^2+bx+c=0: ");
	scanf("%d %d %d",&a,&b,& c);
	//d is the discriminant
	d=(b*b)-(4*a*c);
	if(d>0){
		r1= (-b+sqrt(d))/(2*a);
		r2= (-b-sqrt(d))/(2*a);
		printf("\nTwo distinct real roots exist: %f and %f",r1,r2);
	}
	else if(d==0){
		r1=(-b)/(2*a);
		printf("\nEqual roots exist: %f",r1);
	}
	else{
		printf("\nRoots are imaginary");
	}
}
