#include <stdio.h>
int main(){
    int n,b,r=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    b=n;
    //Reversing the number
    while(b!=0){
        r=(r*10)+(b%10);
        b/=10;
    }
    //Checking if palindrome or not
    if(n==r)
        printf("%d is palindrome",n);
    else
        printf("%d is not palindrome",n);
}