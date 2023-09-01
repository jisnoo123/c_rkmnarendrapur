//point is inside,outside or on the circle
#include <stdio.h>
int main(){
	float x,y,r;
	printf("Enter the (x,y) coordinate and the radius of the circle : ");
	scanf("%f %f %f",&x,&y,&r);
	printf("\n(%g,%g)",x,y);
	if((x*x)+(y*y)-(r*r)>0){
		printf("Point is outside the circle");
	}
	else if((x*x)+(y*y)-(r*r)==0){
		printf("Point is on the circle");
	}
	else{
		printf("Point is inside the circle");
	}
}
