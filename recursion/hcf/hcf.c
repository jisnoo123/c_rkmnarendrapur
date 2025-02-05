#include<stdio.h>
int hcf(int a,int b){
    if(b%a==0){
        return a;
    }
    else{
        return hcf(b%a,a);
    }
}
int main(){
    int a,b;
    printf("Enter smaller and greater number:");
    scanf("%d%d",&a,&b);
    printf("The hcf is %d",hcf(a,b));
}