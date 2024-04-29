#include <stdio.h>

int a,b;

int product(int n){
    if(n==0){
        return 0;
    }
    else{
        return a+product(n-1);
    }
}

int main(){
    printf("\nEnter two numbers:");
    scanf("%d%d",&a,&b);
    int p=product(b);
    printf("\nProduct %dx%d= %d",a,b,p);
}