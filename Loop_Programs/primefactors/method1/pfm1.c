#include <stdio.h>
int main(){
    int n,c=0;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(int i=2;n!=1;){
        if(n%i==0){
            c++;
            printf("\n%d",i);
            n=n/i;
        }
        else{
            i++;
        }
    }
    if(c==0){
        printf("No prime factors");
    }
}