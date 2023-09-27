#include <stdio.h>
int main(){
    int m,n,i,j,k,min,max,n1,f=0;
    int a[100][100];
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&m,&n);
    //input
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("\nenter element: ");
            scanf("%d",&a[i][j]);
        }
    }
    //displaying input
    printf("\nOriginal matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    //calculation
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            n1=a[i][j];
            //min of a row
            min=a[i][j];max=a[i][j];
            for(k=0;k<n;k++){
                if(a[i][k]<min){
                    min=a[i][k];
                }
            }
            for(k=0;k<m;k++){
                if(a[k][j]>max){
                    max=a[k][j];
                }
            }
            if(min==n1 && max==n1){
                f++;
                printf("\nSaddle point %d , row position:%d col position:%d ",n1,i+1,j+1);
            }
        }
    }
    if(f==0){
        printf("\n no saddle point");
    }
    else if(f==m*n){
        printf("\n Every point is saddle point");
    }
}