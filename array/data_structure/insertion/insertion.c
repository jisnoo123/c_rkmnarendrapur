//Insertion of an element into an array
#include <stdio.h>
#define nil -1
int insertion(int *a, int l, int u, int p, int e){
    //Returns 0 if insertion not possible else returns 1
    int i;
    if(a[u]!=nil){
        printf("Array full insertion not possible");
        return 0;
    }
    else{
        i=u;
        while(i>p){
            a[i]=a[i-1];
            i--;
        }
        a[p]=e;
        return 1;
    }
}
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
    for(int i=0;i<100;i++){
        a[i]=nil;
    }
    printf("\nEnter size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&a[i]);
    }
    printf("\nOriginal array:");
    traverse(a,0,n-1);
    printf("\nEnter element to insert: ");
    int e;
    scanf("%d",&e);
    printf("\nEnter index of insertion: ");
    int p;
    scanf("%d",&p);
    int msg=insertion(a,0,n,p,e);
    printf("Message:%d ",msg);
    printf("New array:");
    traverse(a,0,n);
}