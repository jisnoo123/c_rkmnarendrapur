#include <stdio.h>
#define MAX 100
int a[MAX];
int n;

void entry(){
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element:");
        scanf("%d",&a[i]);
    }
}

void compute(){
    int fl=a[0],sl=a[0],tl=a[0];
    //Computes first largest
    for(int i=1;i<n;i++){
        if(fl<a[i]){
            fl=a[i];
        }
    }
    //Computes second largest
    for(int i=1;i<n;i++){
        if(sl<a[i]&&fl>a[i]){
            sl=a[i];
        }
    }
    //Computes third largest
    for(int i=1;i<n;i++){
        if(tl<a[i]&&sl>a[i]){
            tl=a[i];
        }
    }
    printf("\nThird largest:%d",tl);
}

int main(){
    entry();
    compute();
}