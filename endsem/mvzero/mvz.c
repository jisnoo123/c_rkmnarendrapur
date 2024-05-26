#include <stdio.h>
#define MAX 100
int a[MAX],f=0,r=0,z=0,n,c=0;

void entry(){
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element:");
        scanf("%d",&a[i]);
    }
}
void count_z(){
    //Counts the no. of zeros
    for(int i=0;i<n;i++){
        if(a[i]==0){
            z++;
        }
    }
}

void traverse(){
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
}

void move(){
    f=0,r=n-1;
    while(c!=z){
        if(a[f]==0&&a[r]!=0){
            //Swap
            int t=a[r];
            a[r]=a[f];
            a[f]=t;
            f++;
            r--;
            c++;
        }
        if(a[r]==0){
            r--;
            c++;
        }
        if(a[f]!=0){
            f++;
        }
    }
}

int main(){
    entry();
    printf("\nOriginal array:");
    traverse();
    count_z();
    move();
    printf("\nNew array:");
    traverse();
}