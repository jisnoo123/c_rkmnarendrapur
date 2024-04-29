#include <stdio.h>
#define MAX 100
int st[MAX],n,u,l;

void rev(){
    if(u!=l){
        int t=st[u];
        st[u]=st[l];
        st[l]=t;
    }
}

void entry(){
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter data:");
        scanf("%d",&st[i]);
    }
}

void display(){
    for(int i=0;i<n;i++){
        printf("%d ",st[i]);
    }
    printf("\n-----\n");
}

int main(){
    entry();
    //Display
    printf("\nOriginal Array:\n");
    display();
    u=n-1;
    l=0;
    rev();
    printf("\nReversed Array:\n");
    display();
}