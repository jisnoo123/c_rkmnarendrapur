#include <stdio.h>
int main(){
    int a[100][100],b[100][100];
    int m,n,i,j;
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&m,&n);
    //input
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("enter element: ");
            scanf("%d",&a[i][j]);
        }
    }
    //displaying input
    printf("\nOriginal matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    //creating transpose
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            b[i][j]=a[j][i];
        }
    }
    //displaying transpose
    printf("\nTranspose matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
