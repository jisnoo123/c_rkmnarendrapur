#include <stdio.h>
int main(){
    int a=0,b=1,c,i=3;
    //First 10 terms
    printf("%d %d ",a,b);
    for(;i<=10;i++){
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
}
