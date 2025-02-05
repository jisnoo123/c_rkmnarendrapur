#include <stdio.h>
int main(){
    long int t=0,f=0,max=0,r;
    for(int i=1;;i++){
        //finding triangular no.
        printf("\n Index: %d ",i);
        for(int j=1;j<=i;j++){
            t=t+j;
        }
        printf("\n Triangular No: %ld ",t);
        //calculating factors
        printf("Factors: ");
        for(int j=1;j<=t;j++){
            if(t%j==0){
                f++;
                printf("%d ",j);
            }
        }
        printf("\n No. of factors is: %ld",f);
        printf("\n");
        t=0;
        if(f>max){
            max=f;
        }
        printf("Maximum till now: %ld",max);
        printf("\n");
        f=0;
        if(max>500){
            r=t;
            break;
        }
    }
    printf("\nThe required triangular no. is: %ld ",r);
}