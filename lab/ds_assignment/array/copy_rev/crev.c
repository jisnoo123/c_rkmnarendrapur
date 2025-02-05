#include <stdio.h>
#define MAX 10
int a[MAX],r[MAX];

void entry(){
    //Take data elements
    for(int i=0;i<10;i++){
        printf("\nEnter data element:");
        scanf("%d",&a[i]);
    }
}

void copy_rev(){
    int j=0;
    for(int i=9;i>=0;i--){
        r[j]=a[i];
        j++;
    }
    //Reverse done
}

void display(){
    printf("\nReversed order:");
    for(int i=0;i<10;i++){
        printf("%d ",r[i]);
    }
}

int main(){
    entry();
    copy_rev();
    display();
}