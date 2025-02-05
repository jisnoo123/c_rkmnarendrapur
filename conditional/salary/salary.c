#include <stdio.h>
int main(){
	float bs,hra,da,gs=0;
	printf("Enter basic salary: ");
	scanf("%f",&bs);
	if(bs<=10000){
		hra=(20.0/100)*bs;
		da=(80.0/100)*bs;
	}
	else if(bs<=20000){
		hra=(25.0/100)*bs;
		da=(30.0/100)*bs;
	}
	else if(bs>20000){
		hra=(30.0/100)*bs;
		da=(95.0/100)*bs;
	}
	gs=gs+bs+hra+da;
	printf("Gross salary: %g",gs);
}
