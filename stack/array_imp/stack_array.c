#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("Overflow");
    }
    else{
        stack[++top]=item;
    }
}

int pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        int temp=stack[top++];
        return  temp;
    }
}