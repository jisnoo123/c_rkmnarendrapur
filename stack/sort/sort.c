#include <stdio.h>
#include <ctype.h>
#define MAX 100
int top=-1;
int st[MAX];

void push(int n){
    st[++top]=n;
}

int pop(){
    int d;
    if(top!=-1){
        d=st[top--];
        return d;   
    }
}

int main(){
    int num[MAX];
    int n;
    printf("Enter number of numbers you want to sort:");
    scanf("%d",&n);
    printf("\nEnter the numbers:");
    for(int i=0;i<n;i++){
        printf("\nEnter number:");
        scanf("%d",&num[i]);
    }
    //Pushing the first number into the stack

    //Performing operations in the stack

    push(num[0]);

    for(int i=1;i<n;i++){
        if(num[i]>st[top]){
            //If the number to be inserted is greater
            push(num[i]);
        }
        else{
            while((num[i]<=st[top])&&top!=-1){
                //If the number to be inserted is smaller
                printf("%d",pop());
            }
            push(num[i]);
        }
    }
    while(top!=-1){
        printf("%d",pop());
    }
}