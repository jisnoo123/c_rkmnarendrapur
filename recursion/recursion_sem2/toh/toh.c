#include <stdio.h>
//Towers of Hanoi
void toh(int n,char A,char B,char C){
    if(n==1)
        printf("\n%c->%c",A,C);
    else{
        toh(n-1,A,C,B);
        printf("\n%c->%c",A,C);
        toh(n-1,B,A,C);
    }
}

int main(){
    int n;
    char A='A',B='B',C='C';
    toh(3,A,B,C);
}