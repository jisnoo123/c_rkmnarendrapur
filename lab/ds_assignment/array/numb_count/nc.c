#include <stdio.h>
#define MAX 20
int a[MAX],N,e=0,o=0,p=0,n=0,z=0;

void entry(){
    //Take data elements

    printf("\nEnter no. of numbers to input:");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        printf("\nEnter data element:");
        scanf("%d",&a[i]);
    }
}

void count(){
    //Count
    for(int i=0;i<N;i++){
        //Even or odd
        if(a[i]%2==0){
            e++;
        }
        else{
            o++;
        }

        //+ve or -ve
        if(a[i]>=0){
            p++;
        }
        else{
            n++;
        }

        //zeros
        if(a[i]==0){
            z++;
        }
    }
}

void display(){
    printf("\nNumber of even no.s:%d and odd no.s:%d",e,o);
    printf("\nNumber of positive no.s:%d and negative no.s:%d",p,n);
    printf("\nNo. of zeros:%d",z);
}

int main(){
    entry();
    count();
    display();
}