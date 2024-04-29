#include <stdio.h>
#define MAX 100
char a[MAX];
int p;

int str_len(int p){
    if(a[p]=='\0'){
        return 0;
    }
    else{
        return 1+str_len(p+1);
    }
}

int main(){
    printf("\nEnter string:");
    scanf("%s",a);
    p=0;
    int len=str_len(p);
    printf("\nLength of string: %d\n",len);
}