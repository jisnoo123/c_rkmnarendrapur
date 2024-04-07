//Merge two sorted arrays into a sorted array
//incomplete
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
    int a[100],b[100],m,n;
    int c[200];
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter number of elements:");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("Enter element: ");
        scanf("%d",&b[i]);
    }
    
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]>b[j]){
            c[k]=b[j];
            j++;
            k++;
        }
        else{
            c[k]=a[i];
            i++;
            k++;
            j++;
        }
    }
    while(i<n){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<m){
        c[k]=b[j];
        k++;
        j++;
    }
    traverse(c,0,k-1);
}