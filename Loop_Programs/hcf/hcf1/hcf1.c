#include <stdio.h>
int main(){
    int a,b,r;
    printf("Enter two no.s: ");
    scanf("%d %d",&a,&b);
    while(b%a!=0){
        r=b%a;
        b=a;
        a=r;
    }
    printf("HCF: %d",a);
}