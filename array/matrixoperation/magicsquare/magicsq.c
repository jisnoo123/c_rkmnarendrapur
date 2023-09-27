#include <stdio.h>
int main(){
    int n,i,j,i1,j1,c=1,f=0;
    int a[100][100];
    printf("enter size of matrix: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    a[0][n/2]=1;
    c++;
    i=0;j=n/2;
    f=1;
    while(f<=(n*n)){
        i1=i;j1=j;
        i=i-1;
        j=j+1;
        if(i==-1&&(j>=0&&j<n)){
            i=n-1;
        }
        else if(j==n&&(i>=0&&i<n)){
            j=0;
        }
        else if(j==n&&i==-1){
            i=i1+1;
            j=j1;
        }
        else if(a[i][j]!=0){
            i=i1+1;
            j=j1;
        }
        a[i][j]=c;
        printf("\ni: %d j: %d element:%d",i,j,a[i][j]);
        //displaying magic square
        /*printf("\ncount no:%d\n",c);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%3d",a[i][j]);
            }   
        printf("\n");
        }
        */
        c++;
        f++;
    }
    printf("\n");
    //displaying magic square
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}
