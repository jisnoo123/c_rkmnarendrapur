#include <stdio.h>
//1980 Jan 1 Tuesday
int main(){
	int d,m,y,diff,nly,ly,dow,i,c=0;
	printf("Enter day month and year: ");
	scanf("%d/%d/%d",&d,&m,&y);
	diff=0;
	if(y==1980){
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
	}
	else{
		for(i=1980;i<=y-1;i++){
	        if((i%100==0 && i%400==0)|| ((i%100!=0&&i%4==0)))
	            c++;
    	}
    	nly=y-c-1980;
    	ly=c;
    	diff=diff+(ly*366)+(nly*365);
    	if((y%100==0 && y%400==0)|| ((y%100!=0&& y%4==0))){
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
					diff=diff+29;
				case 1:
					diff=diff+31;
			}
			diff=diff+(d-1);
		}
		else{
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
		}	
	dow=diff%7;
	printf("Date of week: ",dow);
	switch (dow){
		case 0:
			printf("Tuesday");
			break;
		case 1:
			printf("Wednesday");
			break;		
		case 2:
			printf("Thursday");
			break;
		case 3:
			printf("Friday");
			break;
		case 4:
			printf("Saturday");
			break;
		case 5:
			printf("Sunday");
			break;
		case 6:
			printf("Monday");
			break;
	}
}
}

