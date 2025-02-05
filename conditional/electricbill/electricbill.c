#include <stdio.h>
int main(){
    float kwh,kva,c;
    int m;
    printf("Enter energy,kva and month: ");
    scanf("%f %f %f",&kwh,&kva,&m);
    c=0;
    if(kwh<=102)
        c=c+(504*kwh);
    else if(kwh<=190)
        c=c+(504*102)+(633*(kwh-102));
    else if(kwh<=310)
        c=c+(504*102)+(633*78)+(712*120)+((kwh-300)*752);
    else if(kwh<=610)
        c=c+(504*102)+(633*78)+(712*120)+((kwh-300)*752);
    else
        c=c+(504*102)+(633*78)+(712*120)+(752*300)+((kwh-600)*769);
    //Adding fixed charge
    c/=100;
    c=c+30;
    printf("Final charge: Rs.%f ",c);
}
