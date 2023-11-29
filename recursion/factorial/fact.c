#include <stdio.h>
int fact(int n){
    //n!=(n-1)! * n
    if(n==1){
        return 1;
    }
    else {
        return n * fact(n-1);
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\nThe factorial is :%d",fact(n));
}