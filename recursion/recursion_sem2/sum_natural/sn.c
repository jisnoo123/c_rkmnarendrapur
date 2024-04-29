#include <stdio.h>
//Sum of natural numbers

int sum_nat(int n){
    if(n==1){
        return 1;
    }
    else{
        return n+sum_nat(n-1);
    }
}

int main(){
    int n;
    printf("\nEnter upto which term the sum will be calculated:");
    scanf("%d",&n);
    int s=sum_nat(n);
    printf("\nSum: %d ",s);
}