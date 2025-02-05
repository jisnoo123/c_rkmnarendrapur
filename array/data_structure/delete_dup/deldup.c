#include<stdio.h>
void traverse(int *a, int l, int u){
    //Here l and u are the two indices of taversing
    int i=l;
    while(i<=u){
        printf("%d ",a[i]);
        i++;
    }
}

int main(){
    int a[100],n;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nOriginal Array:");
    traverse(a,0,n-1);
    //Delete duplicate array
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=j;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\nNew Array:");
    traverse(a,0,n-1);
}