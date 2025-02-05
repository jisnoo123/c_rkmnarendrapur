#include <stdio.h>
#include <math.h>
int main(){
    int n,b,c=0,s=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    b=n;
    //Calculating no. of digits
    while(b!=0){
        b/=10;c++;
    }
    b=n;
    //Calculating sum as digit ^ no. of digits
    while(b!=0){
        s=s+(pow(b%10,c));
        b/=10;
    }
    //Checking
    if(n==s)
        printf("%d is armstrong",n);
    else
        printf("%d is not armstrong",n);
}