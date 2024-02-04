#include <stdio.h>
#define MAX 100
void search(int key,int *a,int n){
    int f=0;
    for(int i=0;i<n;i++){
        if(key==a[i]){
            f++;
            printf("\nFound at %d index",i);
            break;
        }
    }
    if(f==0)
        printf("\nNot found");
}
int main(){
    int a[MAX],n,key;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter key value: ");
    scanf("%d",&key);
    search(key,a,n);
}