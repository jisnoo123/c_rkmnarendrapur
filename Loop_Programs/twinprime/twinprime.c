#include <stdio.h>
int main(){
    int counti,countj,next;
    for(int i=2;i<=1000;i++){
        counti=0;
        for(int k=1;k<=i;k++){
            if(i%k==0)
                counti++;
        }
        if(counti==2){
            countj=0;
            next=i+2;
            //printf("\nCurrent i=%d next=%d",i,next);
            for(int j=1;j<=next;j++){
                if(next%j==0)
                    countj++;
            }
            if(countj==2)
                printf("\n %d %d",i,next);
        }
    }
}