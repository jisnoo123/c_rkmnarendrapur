#include <stdio.h>
#define MAX 10
int a[MAX],b[MAX/2],c[MAX/2];

void entry(){
    //Take data elements
    for(int i=0;i<10;i++){
        printf("\nEnter data element:");
        scanf("%d",&a[i]);
    }
}

void split(){
    int j=0;
    //Keep in b[]
    for(int i=0;i<5;i++,j++){
        b[j]=a[i];
    }

    //Keep in c[]
    j=0;
    for(int i=5;i<10;i++,j++){
        c[j]=a[i];
    }
}

void display(){
    printf("\nIn first array:");
    for(int i=0;i<5;i++){
        printf("%d ",b[i]);
    }

    printf("\nIn second array:");
    for(int i=0;i<5;i++){
        printf("%d ",c[i]);
    }    
}

int main(){
    entry();
    split();
    display();
}