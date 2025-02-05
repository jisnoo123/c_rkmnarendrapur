#include <stdio.h>
int main(){
    int n,c=0;
    printf("enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(n%i==0){
            for(int j=1;j<=i;j++){
                if(i%j==0)
                    c++;
            }
            if(c==2)
                printf("\n%d",i);
            c=0;            
        }
    }
    printf("\n");
}