//Find the second largest number among 3 no.s without using loop
#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter the three no.s: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && b>c)
        printf("\nSecond largest: %d",b);
    else if(b>a && a>c)
        printf("\nSecond largest: %d",a);
    else if(b>c && c>a)
        printf("\nSecond largest: %d",c);
    else
        printf("\nAll three are equal ");
}
