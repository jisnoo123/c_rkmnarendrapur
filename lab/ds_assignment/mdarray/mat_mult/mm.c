#include <stdio.h>
#define MAX 10
int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
int m,n,p;

void entry(){
    printf("\nEnter size of the first matrix:");
    scanf("%d %d",&m,&n);
    printf("\nEnter the elements of first matrix:");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("\nEnter element:");
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter size of the second matrix:");
    scanf("%d %d",&n,&p);
    printf("\nEnter the elements of first matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("\nEnter element:");
            scanf("%d",&b[i][j]);
        }
    }
}

void construct(){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            c[i][j]=0;
        }
    }
}

void mult(){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}

void display(){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

int main(){
    entry();
    construct();
    mult();
    display();
}