#include <stdio.h>
#define MAX 100
int n1,n2,c;
int a[MAX],b[MAX],u[MAX];

void entry(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("\nEnter element:");
        scanf("%d",&arr[i]);
    }
}

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void un(){
    //union of two arrays
    for(int i=0;i<n1;i++){
        u[i]=a[i];
    }
    c=n1;
    for(int i=0;i<n2;i++){
        int count=0;
        for(int j=0;j<n1;j++){
            if(b[i]==a[j]){
                count++;
            }
        }
        if(count==0){
            u[c]=b[i];
            c++;
        }
    }
}

int main(){
    printf("\nEnter size of first array:");
    scanf("%d",&n1);
    entry(a,n1);
    printf("\nEnter size of second array:");
    scanf("%d",&n2);
    entry(b,n2);
    printf("\nFirst array:");
    display(a,n1);
    printf("\nSecond array:");
    display(b,n1);
    un();
    printf("\nUnion:");
    display(u,c);
}