#include <stdio.h>
#define MAX 100
int arr[MAX],mid,n,l,u,f=0;

void entry(){
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element:");
        scanf("%d",&arr[i]);
    }
}

void binsearch(int *a,int l,int u,int key){
    mid=(l+u)/2;
    if(l>u){
        printf("\nNot found");
    }
    else if(a[mid]==key){
        printf("\nFound at %d index",mid);
    }   
    else if(a[mid]>key){
        binsearch(a,l,mid-1,key);
    }
    else if(a[mid]<key){
        binsearch(a,mid+1,u,key);
    }
}

int main(){
    entry();
    int key;
    printf("\nEnter key:");
    scanf("%d",&key);
    l=0;
    u=n-1;
    binsearch(arr,l,u,key);
}