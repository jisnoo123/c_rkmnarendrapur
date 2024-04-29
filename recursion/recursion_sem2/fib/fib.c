#include <stdio.h>

int fib(int n){
    if(n==1)
        return 0;
    else if(n==2) 
        return 1;
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main(){
    int n;
    printf("\nEnter upto which term the sequence will be shown:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d ",fib(i));
    }
}