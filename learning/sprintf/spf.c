#include <stdio.h>
int main(){
    int d=42;
    char a[100];
    sprintf(a,"%d",d);
    printf("The value is %s",a);
}