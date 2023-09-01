#include <stdio.h>
int main(){
    long int n,b,d=0; int c=1;
    printf("Enter a binary number: ");
    scanf("%ld",&n);
    b=n;
    while(b!=0){
        d=d+(c*(b%10));
        b/=10;
        c*=2;
    }
    printf("Decimal equivalent: %ld",d);
}