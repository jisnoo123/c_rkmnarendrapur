#include <stdio.h>
int main(){
    int n,ci=0,cj=0,flag=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            for(int k=1;k<=i;k++){
                if(i%k==0)
                    ci++;
            }
            for(int k=1;k<=j;k++){
                if(j%k==0)
                    cj++;
            }
            if(ci==2&&cj==2){
                if(i*j==n){
                    printf("%d X %d = %d",i,j,n);
                    flag++;
                    break;
                }
            }
            ci=0;cj=0;
        }
        if(flag!=0)
            break;
    }
    if(flag!=0)
        printf("\n%d is semiprime",n);
    else    
        printf("\n%d is not semiprime",n);

}