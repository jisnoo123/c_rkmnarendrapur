#include <stdio.h>
#define MAX 10
int a[MAX],b[MAX],n;

void entry(){
    //Take data elements
    printf("\nEnter no. of numbers to input:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter data element for first array:");
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        printf("\nEnter data element for second array:");
        scanf("%d",&b[i]);
    }    
}

void check(){
    int f=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            f++;
            break;
        }
    }

    if(f==0){
        printf("\nSame array");
    }
    else{
        printf("\nNot same arrays");
    }
}

int main(){
    entry();
    check();
}