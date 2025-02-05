//To test whether a number is perfect or not
#include <stdio.h>
int main(){
    int n,s=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        if(n%i==0)
            s=s+i;
    }
    if(s==n)
        printf("%d is perfect",n);
    else    
        printf("%d is not perfect",n);
}