/*Sum of first n natural numbers
S(n)=1+2+3+4+.....+n */
#include <stdio.h>
int sum(int n){
    //S(n)=S(n-1)+n
    if(n==1){
        return 1;
    }
    else{
        return sum(n-1)+n;
    }
}
int main(){
    int n;
    printf("Enter the number upto which sum of natural numbers needs to be calculated: ");
    scanf("%d",&n);
    printf("\nSum is %d",sum(n));
}