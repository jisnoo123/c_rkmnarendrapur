#include <stdio.h>
#include <math.h>
int main(){
    int i,b,c,s;
    for(i=1;i<=1000;i++){
        b=i;s=0,c=0;
        //Calculating no. of digits
        while(b!=0){
            b/=10;c++;
        }
        b=i;
        //Calculating sum as digit ^ no. of digits
        while(b!=0){
            s=s+(pow(b%10,c));
            b/=10;
        }
        //Checking
        if(i==s)
            printf("%4d",i);
    }
}
