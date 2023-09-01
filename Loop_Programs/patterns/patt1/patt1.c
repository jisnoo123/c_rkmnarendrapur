#include<stdio.h>
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=6-i;j++){
            printf("%c",'A'+(j-1));
        }
        for(int g=1;g<=2*i-3;g++){
            printf(" ");
        }
        for(int j=1;j<=6-i;j++){
            printf("%c",'A'+(5-j));
        }
        printf("\n");
    }
}