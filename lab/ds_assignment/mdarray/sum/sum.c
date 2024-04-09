//To display sum of each row and column 
#include <stdio.h>
#define MAX 100
int a[MAX][MAX],m,n;

void display(){
    printf("\nMatrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void entry(){
    printf("\nEnter number of rows and columns of the matrix:");
    scanf("%d %d",&m,&n);
    printf("\nTaking elements of 2d array......");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("\nEnter element:");
            scanf("%d",&a[i][j]);
        }
    }
}

int sum_row(int row){
    int sum=a[row][0];
    for(int i=1;i<n;i++){
        sum+=a[row][i];
    }
    printf("\nSum of row %d is : %d",row+1,sum);
}

int sum_col(int col){
    int sum=a[0][col];
    for(int i=1;i<m;i++){
        sum+=a[i][col];
    }
    printf("\nSum of column %d is : %d",col+1,sum);
}

int main(){
    entry();
    display();
    //Displaying sum of rows
    for(int i=0;i<m;i++){
        sum_row(i);
    }
    //Displaying sum of columns
    for(int i=0;i<n;i++){
        sum_col(i);
    }
}