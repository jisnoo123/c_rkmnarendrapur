#include <stdio.h>
#define MAX 100
int main(){
    char exp[MAX];char *e;
    int lp=0,rp=0;
    printf("\nEnter the expression:");
    scanf("%s",exp);
    e=exp;
    while((*e)!='\0'){
        if(*e=='(')
            lp++;
        else if(*e==')')
            rp++;
        e++;
    }
    if(lp==rp){
        printf("\nBalanced parentheses");
    }
    else{
        printf("\nNot balanced parentheses");
    }
}