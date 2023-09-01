#include <stdio.h>
int main(){
    int a,b;
    printf("Enter two no.s: ");
    scanf("%d %d",&a,&b);
    while(b!=a){
        if(b>a){
            b=b-a;
        }
        else{
            a=a-b;
        }
    }
    printf("HCF: %d",a);
}