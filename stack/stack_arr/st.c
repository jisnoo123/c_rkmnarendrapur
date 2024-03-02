#include <stdio.h>
#define MAX 50
int top=-1;

void traverse(int *a){
    int i=top;
    printf("\nYour stack is:");
    while(i>=0){
        printf("\n%d",a[i]);
        i--;
    }
    printf("\n");
}

void status(int *a,int n){
    printf("\n");
    if(top==n){
        printf("\nOverflow");
    }
    else if(top==-1){
        printf("\nStack empty");
    }
    else{
        printf("\nValue of top:%d",top);
        traverse(a);
    }
}

void pop(int *a,int n){
    printf("\n");
    if(top==-1){
        printf("\nUnderflow");
    }
    else{
        printf("\nElement is %d",a[top--]);
    }
}

void push(int *a,int n){
    printf("\n");
    if(top==n-1){
        printf("\nOverflow");
    }
    else{
        int item;
        printf("\nEnter element to insert: ");
        scanf("%d",&item);
        a[++top]=item;
    }
    
}

int main(){
    int inp,n;
    int a[MAX];
    printf("\nEnter size of stack: ");
    scanf("%d",&n);
    do{
        printf("\nEnter 1 for push, 2 for pop, 3 for status and 4 to stop:");
        scanf("%d",&inp);
        switch(inp){
                case 1:
                    push(a,n);
                    break;
                case 2:
                    pop(a,n);
                    break;
                case 3:
                    status(a,n);
                    break;
                case 4:
                    break;
        }

    }
    while(inp!=4);
}