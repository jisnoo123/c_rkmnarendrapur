#include <stdio.h>
int main(){
    long int n,c=0,max=0,r;
    for(long int i=1;i<1000000;i++){
        n=i;
        while(n!=1){
            if(n%2==0){
                n=n/2;
            }
            else{
                n=3*n+1;
            }
            c++;
        }
        if(c>max){
            max=c;
            r=i;
        }
        c=0;
    }
    printf("Required number: %ld ",r);
    printf("\n Maximum paths: %ld",max);
}