#include <stdio.h>

int sum_digit(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n%10)+sum_digit(n/10);
    }
}

int main(){
    int n,s;
    printf("\nEnter number:");
    scanf("%d",&n);
    s=sum_digit(n);
    printf("\nSum:%d\n",s);
}