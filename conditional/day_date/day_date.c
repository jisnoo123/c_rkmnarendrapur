#include <stdio.h>
//Jan 1 2023 - Sunday
int main(){
	int d,m,y,dow,diff;
	printf("Enter day month and year: ");
	scanf("%d/%d/%d",&d,&m,&y);
	diff=0;
	switch(m-1){
		case 11:
			diff=diff+30;
		case 10:
			diff=diff+31;
		case 9:
			diff=diff+30;
		case 8:
			diff=diff+31;
		case 7:
			diff=diff+31;
		case 6:
			diff=diff+30;
		case 5:
			diff=diff+31;
		case 4:
			diff=diff+30;
		case 3:
			diff=diff+31;
		case 2:
			diff=diff+28;
		case 1:
			diff=diff+31;
	}
	diff=diff+(d-1);
	dow=diff%7;
	switch (dow){
		case 0:
			printf("Sunday");
			break;
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
	}
}
