#include <stdio.h>
int main(){
    int i,arr[100],n,k,lb,ub,mid,pass,j,t;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter sorted array ");
    for(i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter key value: ");
    scanf("%d",&k);
    printf("\n");
    lb=0;ub=n-1;
    mid=(lb+ub)/2;
    while(lb<=ub){
        if(arr[mid]==k){
            printf("\nFound at %d index",mid);
            break;
        }
        else if (arr[mid]<k){
            lb=mid+1;
            mid=(lb+ub)/2;
        }
        else if(arr[mid]>k){
            ub=mid-1;
            mid=(lb+ub)/2;
        }
    }
    if(lb>ub)
        printf("Element not found");
}
