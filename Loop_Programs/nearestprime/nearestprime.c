#include <stdio.h>
int main(){
    int n,c=0,r,l,dr,dl;
    printf("Enter a number: ");
    scanf("%d",&n);
    //To the right
    for(int i=n+1; ; i++){
        for(int j=1;j<=i;j++){
            if(i%j==0)
                c++;
        }
        if(c==2){
            r=i;
            break;
        }
        c=0;
    }
    printf("\nRight:%d",r);
    c=0;
    //To the left
    for(int i=n-1; ; i--){
        for(int j=1;j<=i;j++){
            if(i%j==0)
                c++;
        }
        if(c==2){
            l=i;
            break;
        }
        c=0;
    }
    printf("\nLeft:%d",l);
    dr=r-n;
    dl=n-l;
    if(dl<dr)
        printf("\nNearest prime: %d",l);
    else if(dl>dr)
        printf("\nNearest prime: %d",r);
    else 
        printf("\nBoth %d and %d are equidistant",l,r);
}