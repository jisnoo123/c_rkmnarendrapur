//Mean snd standard variation
#include <stdio.h>
#include <math.h>
#define MAX 10
float a[MAX];int n;

void entry(){
    //Take data elements
    printf("\nEnter number of data elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter data :");
        scanf("%f",&a[i]);
    }
}

void mean_sd(){
    float mean,sd,sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }
    mean=sum/n;
    sum=0;
    for(int i=0;i<n;i++){
        sum=sum+pow((a[i]-mean),2);
    }
    sd=sqrt(sum/n);
    printf("\nMean is %f and Variance is %f",mean,sd);
}

int main(){
    entry();
    mean_sd();
}