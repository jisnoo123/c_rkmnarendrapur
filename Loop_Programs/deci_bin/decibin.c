#include <stdio.h>
int main(){
    int d,r,w=1;
    long int b=0;
    printf("Enter decimal number: ");
    scanf("%d",&d);
    while(d!=0){
        r=d%2;
        b=b+(r*w);
        w*=10;
        d/=2;
    }
    printf("Binary: %ld",b);
}
