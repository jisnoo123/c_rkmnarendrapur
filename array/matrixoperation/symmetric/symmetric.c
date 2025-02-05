#include <stdio.h>
int main(){
    int a[100][100],b[100][100];
    int n,i,j,flag;
    printf("Enter size of square matrix: ");
    scanf("%d",&n);
    //input
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("enter element: ");
            scanf("%d",&a[i][j]);
        }
    }
    //displaying input
    printf("\nOriginal matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    //symmetric checking
    flag=0;
    for(i=0;i<=n-2;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=a[j][i]){
                flag++;
                break;
            }
        }
        if(flag==1) break;
    }
    if(flag==0)
        printf("\nsymmetric matrix");
    else
        printf("\nnot symmetric");
}
