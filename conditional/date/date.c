//If 1980 Jan 1 is Tuesday , take an input and then display the day
#include <stdio.h>
int main(){
    int d,m,y,c=0,nly,days,i;
    printf("Enter day,month and days: ");
    scanf("%d %d %d",&d,&m,&y);
    for(i=1980;i<=y;i++){
        if((i%100==0 && i%400==0)|| ((i%100!=0&&i%4==0)))
            c++;
    }
    nly=(y-c);
    if(y==1980){
    	if(m==1)
    		days=d;
    	else if(m==2)
    		days=31+(d);
    	else if(m==3)
    		days=31+28+(d);
    	else if(m==4)
    		days=31+28+31+(d);
    	else if(m==5)
    		days=31+28+31+30+(d);
    	else if(m==6)
    		days=31+28+31+30+31+(d);
    	else if(m==7)
    		days=31+28+31+30+31+30+(d);
    	else if(m==8)
    		days=31+28+31+30+31+30+31+(d);
    	else if(m==9)
    		days=31+28+31+30+31+30+31+31+(d);
    	else if(m==9)
    		days=31+28+31+30+31+30+31+31+30+(d);
    	else if(m==10)
    		days=31+28+31+30+31+30+31+31+30+31+(d);
    	else if(m==11)
    		days=31+28+31+30+31+30+31+31+30+31+30+(d);
    	else if(m==12)
    		days=31+28+31+30+31+30+31+31+30+31+30+31+(d);
	}
	else{
		days= (nly*365)+(c*366);
	}
    if(days%7==1)
        printf("Monday");
    else if(days%7==2)
        printf("Tuesday");
    else if(days%7==3)
        printf("Wednesday");
    else if(days%7==4)
        printf("Thursday");
    else if(days%7==5)
        printf("Friday");
    else if(days%7==6)
        printf("Saturday");
    else 
        printf("Sunday");
}
