#include <stdio.h>
int main(){
    int a,b,a1,b1,r;
    printf("Enter two no.s: ");
    scanf("%d %d",&a,&b);
    a1=a; b1=b;
    while(b%a!=0){
        r=b%a;
        b=a;
        a=r;
    }
    printf("HCF: %d",a);
    printf("\n");
    if(a==1){
        printf("%d and %d are coprime ",a1,b1);
    }
    else{
        printf("%d and %d are not coprime ",a1,b1);
    }
}