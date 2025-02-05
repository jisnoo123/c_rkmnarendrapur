#include <stdio.h>
#define MAX 100
int n;
void traverse(int *a, int l, int u){
    //Here l and u are the two indices of taversing
    int i=l;
    while(i<=u){
        printf("%d ",a[i]);
        i++;
    }
    printf("\nTraversing completed");
}
int search(int key,int *a){
    //Returns index if found else returns -1
    int f=0;
    for(int i=0;i<n;i++){
        if(key==a[i]){
            f++;
            return i;
            break;
        }
    }
    if(f==0){
        return -1;
    }
}
void delete(int key,int *a){
    int i=search(key,a);
    if(i!=-1){
        while(i<n-1){
            a[i]=a[i+1];
            i++;
        }
        n--;
        printf("\nNew array:");
        traverse(a,0,n-1);
    }
    else{
        printf("\nElement not in the array");
    }
}
int main(){
    int a[MAX],key;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter key value: ");
    scanf("%d",&key);
    printf("\nOriginal array:");
    traverse(a,0,n-1);
    delete(key,a);
}