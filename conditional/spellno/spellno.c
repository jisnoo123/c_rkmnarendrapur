
//Spell the no. from 0 to 99
#include <stdio.h>
int main(){
    int n,b;
    printf("Enter a number: ");
    scanf("%d",&n);
    //No. is between 0 to 9
    if(n<10){
        if(n==1)
            printf("One");
        else if(n==2)
            printf("Two");
        else if(n==3)
            printf("Three");
        else if(n==4)
            printf("Four");
        else if(n==5)
            printf("Five");
        else if(n==6)
            printf("Six");
        else if(n==7)
            printf("Seven");
        else if(n==8)
            printf("Eight");
        else if(n==9)
            printf("Nine");
        else    
            printf("Zero");
    }
    //No. is from 10 to 19
    if(n>9 && n<20){
        if(n==10)
            printf("Ten");
        else if(n==11)
            printf("Eleven");
        else if(n==12)
            printf("Twelve");
        else if(n==13)
            printf("Thirteen");
        else if(n==14)
            printf("Fourteen");
        else if(n==15)
            printf("Fifteen");
        else if(n==16)
            printf("Sixteen");
        else if(n==17)
            printf("Seventeen");
        else if(n==18)
            printf("Eighteen");
        else if(n==19)
            printf("Nineteen");
    }
    //No. is from 20 to 99
    b=n;
    if(n>=20 && n<100){
        //Displaying ten's place
        if(n>=20 && n<=29)
            printf("Tewnty");
        else if (n>=30 && n<=39)
            printf("Thirty");
        else if (n>=40 &&n<=49)
            printf("Fourty");
        else if (n>=50 && n<=59)
            printf("Fifty");
        else if(n>=60 && n<=69)
            printf("Sixty");
        else if(n>=70 && n<=79)
            printf("Seventy");
        else if(n>=80 && n<=89)
            printf("Eighty");
        else 
            printf("Ninety");   
        //Displaying one's place
        b=b%10;
        if(b!=0){
	        if(b==1)
	            printf(" One");
	        else if(b==2)
	            printf(" Two");
	        else if(b==3)
	            printf(" Three");
	        else if(b==4)
	            printf(" Four");
	        else if(b==5)
	            printf(" Five");
	        else if(b==6)
	            printf(" Six");
	        else if(b==7)
	            printf(" Seven");
	        else if(b==8)
	            printf(" Eight");
	        else if(b==9)
	            printf(" Nine");
	        else    
	            printf(" Zero"); 
    	}
    }
    //No. is 100
    if(n==100)
        printf("Hundred");
}
