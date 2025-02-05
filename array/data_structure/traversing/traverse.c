#include <stdio.h>
void traverse(int *a, int l, int u){
    //Here l and u are the two indices of taversing
    int i=l;
    while(i<=u){
        printf("%d ",a[i]);
        i++;
    }
    printf("\nTraversing completed");
}

int main(){
    int a[100];
    int n;
    printf("\nEnter size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&a[i]);
    }
    traverse(a,0,n-1);
}