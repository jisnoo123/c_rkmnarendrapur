//To test whether a number is perfect or not
#include <stdio.h>
int main(){
    int n,i,s;
    for(n=1;n<=1000;n++){
    	s=0;
        for(i=1;i<n;i++){
            if(n%i==0)
                s=s+i;
        }
        if(s==n)
            printf("%4d",n);
    }
}
