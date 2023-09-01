#include <stdio.h>
int main(){
    int n;
    float obs,s=0.0;
    printf("Enter number of observations: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\nEnter the observation : ");
        scanf("%f",&obs);
        s=s+obs;
    }
    printf("\nMean is : %g ",(s/n));
}