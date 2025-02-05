//To display maximum element of 2D array
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

int max_row(int row){
    int max=a[row][0];
    for(int i=1;i<n;i++){
        if(a[row][i]>max){
            max=a[row][i];
        }
    }
    return max;
}

int main(){
    entry();
    display();
    int m;
    //Displaying max element of each row
    m=max_row(0);
    for(int i=1;i<m;i++){
        if(max_row(i)>m){
            m=max_row(i);
        }
    }
    printf("\nMaximum element of 2D matrix is:%d",m);
}