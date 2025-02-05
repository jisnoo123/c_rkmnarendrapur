#include <stdio.h>
int main(){
    int n,max,num;
    printf("Enter number of no.s: ");
    scanf("%d",&n);
    printf("\nEnter first number: ");
    scanf("%d",&max);
    for(int i=2;i<=n;i++){
        printf("\nEnter number : ");
        scanf("%d",&num);
        if(num>max)
            max=num;
    }
    printf("\nMaximum number is : %d ",max);
}