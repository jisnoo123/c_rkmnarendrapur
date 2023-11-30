#include <stdio.h>
void one(int n){
    if(n==1)
        printf(" 1 ");
    else{
        one(n-1);
        printf(" %d ",n);
    } 
}
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    one(n);
}