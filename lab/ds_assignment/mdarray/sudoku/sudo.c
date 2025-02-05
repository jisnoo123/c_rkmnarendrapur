//To display maximum element of 2D array
#include <stdio.h>
#define MAX 100
int a[MAX][MAX],m,n;

void display(){
    printf("\nSudoku:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void entry(){
    printf("\nEnter number of rows and columns:");
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("\nEnter element:");
            scanf("%d",&a[i][j]);
        }
    }
}

int count(int num){
    int c=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==num)
                c++;
        }
    }
    return c;
}

int main(){
    entry();
    display();
    int m;
    //Displaying max element of each row
    for(int i=0;i<=9;i++){
        int ci=count(i);
        printf("\n%d occurs %d times",i,ci);
    }
}