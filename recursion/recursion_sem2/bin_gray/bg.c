#include <stdio.h>
//Binary to gray

int bingray(int b){
    if(b==0)
        return 0;
    int ld=b%10;
    int sld=(b/10)%10;

    if((ld==1&&sld==0)||(ld==0&&sld==1)){
        return 1+10*bingray(b/10);
    }
    else{
        return 10*bingray(b/10);
    }
}

int main(){
    int b;
    printf("\nEnter binary number:");
    scanf("%d",&b);
    int g=bingray(b);
    printf("\nGray code:%d",g);
}