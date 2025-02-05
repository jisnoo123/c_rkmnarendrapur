#include <stdio.h>
#define MAX 100
int top=-1;
char st[MAX];

void push(char *e){
    st[++top]=*e;
}

void pop(){
    printf("%c",st[top--]);
}

int main(){
    char str[MAX];
    printf("\nEnter a string:");
    scanf("%s",&str);
    char *e=str;
    while((*e)!='\0'){
        push(e);
        e++;
    }
    //Displaying
    printf("\nReversed string:");
    while(top!=-1){
        pop();
    }
}