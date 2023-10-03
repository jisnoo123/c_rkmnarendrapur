#include <stdio.h>
int main(){
    float c,f;
    printf("Enter temperature in centigrade: ");
    scanf("%f",&c);
    f=(9*c+160)/5;
    printf("Fahrenheit temperature: %f",f);
}