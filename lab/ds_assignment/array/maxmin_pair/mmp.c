#include <stdio.h>
#define MAX 10
int a[MAX],g[2],l[2],n;

void entry(){
    //Take data elements
    printf("\nEnter no. of numbers to input:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter data element:");
        scanf("%d",&a[i]);
    }
}

void find(){
    g[0]=a[0];
    g[1]=a[1];
    l[0]=a[0];
    l[1]=a[1];
    int maxd=a[0]-a[1],mind=a[0]-a[1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n&&j!=i;j++){
            if(a[i]-a[j]>maxd){
                maxd=a[i]-a[j];
                g[0]=a[i];
                g[1]=a[j];
            }
            
            if(a[i]-a[j]<mind){
                mind=a[i]-a[j];
                l[0]=a[i];
                l[1]=a[j];
            }
        }
    }
}

void display(){
    //Max diff pair
    if(g[0]>g[1]){
        printf("Max diff pair: (%d,%d)",g[0],g[1]);
    }
    else{
        printf("Max diff pair: (%d,%d)",g[1],g[0]);
    }

    //Min diff pair
    if(l[0]>l[1]){
        printf("Max diff pair: (%d,%d)",l[0],l[1]);
    }
    else{
        printf("\nMax diff pair: (%d,%d)",l[1],l[0]);
    }
}

int main(){
    entry();
    find();
    display();
}