#include <stdio.h>

void decibin(int d){
    if(d==1)
        printf("%d",d);
    else{
        decibin(d/2);
        printf("%d",(d%2));
    }
}

int main(){
    int dec;
    printf("Enter decimal number:");
    scanf("%d",&dec);
    printf("\nBinary:");
    decibin(dec);
}