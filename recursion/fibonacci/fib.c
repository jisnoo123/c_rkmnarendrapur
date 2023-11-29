#include <stdio.h>
int fib(int n){
    //Here n is the number(position) of the fibonacci term
    if(n==1)
        return 0;
    else if (n==2)
        return 1;
    else 
        return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    printf("Enter the number of fibonacci term");
    scanf("%d",&n);
    int a=fib(n);
    printf("\nIt is %d",a);
}