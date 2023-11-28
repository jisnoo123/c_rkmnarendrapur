#include <stdio.h>
#include <stdlib.h>
void isprime(int n){
    int d,count=0;
    for(d=1;d<=n;d++){
        if(n%d==0){
            count++;
        }
    }
    if(count==2)
        printf("\n%d",n);
}
int main(int argc,char *argv[]){
    int i,n;
    FILE *fp;
    fp = fopen(argv[1],"r");
    while(!feof(fp)){
        fscanf(fp,"%d",&n);
        isprime(n);
    }
    fclose(fp);
}