#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int st[MAX],top=-1;

void push(int *data){
    st[++top]=*data;
}

int pop(){
    if(top==-1)
        return -99;
    else 
        return st[top--];
}

bool isoperator(char e){
    if(e=='+'||e=='-'||e=='/'||e=='*')
        return true;
    else   
        return false;
}

int calc(int x,int y,char e){
    switch(e){
        case '+':
            return x+y;
            break;
        case '-':
            return x-y;
            break;
        case '*':
            return x*y;
            break;
        case '/':
            return x/y;
            break;
    }
}
int main(){
    printf("\nEnter expression:");
    char e;
    while((e=getchar())!='\n'){
        if(!isoperator(e)){
            //operand
            int *dataptr=(int *)(malloc(sizeof(int)));
            *dataptr=atoi(&e);
            push(dataptr);
        }
        else{
            //operator
            int x,y;
            y=pop();
            x=pop();
            int val=calc(x,y,e);
            push(&val);
        }
    }

    //Value at the top is the result
    printf("\nEvaluated postfix expression:%d",st[top]);
}