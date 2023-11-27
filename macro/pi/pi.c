#define pi 3.14
#include <stdio.h>
int main(){
    float r,a;
    printf("Enter the radius of circle:");
    scanf("%f",&r);
    a=pi*r*r;
    printf("\nArea of circle:%f sq. units",a);
}
/*Output:
Enter the radius of circle:4.5

Area of circle:63.584999 sq. units
*/