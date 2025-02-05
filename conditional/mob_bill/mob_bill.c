#include <stdio.h>
int main(){
    int c;
    float b=200; //Rs.200 fixed charge
    printf("Enter number of calls: ");
    scanf("%d",&c);
    if(c>=200&&c<=300){
        //Rs.5 per call above 200 calls
        b=b+5*(c-200);
    }
    else if(c<=400){
        //Rs.6 per call above 300
        b=b+5*100+6*(c-300);
    }
    else if(c<=500){
        //Rs.7 per call above 400
        b=b+5*100+6*100+(c-400)*7;
    }
    else{
        //Rs.10 per call above 500
        b=b+5*100+6*100+100*7+(c-500)*10;
    }
    printf("%f : Bill",b);
}
