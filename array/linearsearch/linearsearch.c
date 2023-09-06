#include <stdio.h>
int main(){
    int a[100],n,key,i,flag=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter key value: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(key==a[i]){
            flag++;
            break;
        }
    }
    if(flag==1){
        printf("Element found at %d index",i);
    }
    else{
        printf("Element not found");
    }
}
