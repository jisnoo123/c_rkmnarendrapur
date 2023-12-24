#include <stdio.h>
int main(){
    int a=3,n=5,m=6;
    int *p=&m;
    a=*p+++n;
    printf("%d",a);
}