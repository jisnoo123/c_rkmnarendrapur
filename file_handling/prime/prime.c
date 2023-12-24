#include<stdio.h>
int isprime(int n){
    int count=0,i;
    for(i=1;i<=n;i++){
        if(n%i==0)
            count++;
    }
    if(count==2)
        return 1;
    else
        return 0;
}
int main(){
    FILE *fp;
    int num;
    fp=fopen("datanum.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        if(isprime(num))
            printf("\n%d",num);
    }
}