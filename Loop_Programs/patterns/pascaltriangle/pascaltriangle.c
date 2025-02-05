#include <stdio.h>
//Pascal's Triangle : (a+b)^n: Coefficient print 
int main(){
    int a,c,row,fn=1,fr=1,fd=1;
    printf("Enter no. of rows of the pattern: ");
    scanf("%d",&row);
    for(int n=0;n<=row;n++){
        for(int r=0;r<=n;r++){
            for(int k=1;k<=n;k++){
                fn=fn*k;
            }
            for(int k=1;k<=r;k++){
                fr=fr*k;
            }
            for(int k=1;k<=n-r;k++){
                fd=fd*k;
            }
            c=fn/(fr*fd);
            fn=1;fr=1;fd=1;
            printf("%d ",c);
        }
        printf("\n");
    }
}