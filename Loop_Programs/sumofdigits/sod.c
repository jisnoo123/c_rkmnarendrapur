#include <stdio.h>
int main(){
    int n,s=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n!=0){
        s=s+(n%10);
        n/=10;
    }
    printf("Sum of digits: %d",s);
}
