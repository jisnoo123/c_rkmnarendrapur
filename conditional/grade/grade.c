#include <stdio.h>
int main(){
    float m;
    printf("Enter marks: ");
    scanf("%f",&m);
    if(m>=80)
        printf("Grade A");
    else if(m>=60)
        printf("Grade B");
    else if(m>=40)
        printf("Grade C");
    else 
        printf("Grade D");
}