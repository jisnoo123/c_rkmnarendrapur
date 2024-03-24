#include <stdio.h>
#define MAX 100
char st[MAX],top=-1;

void push(char d){
    st[++top]=d;
}

char pop(){
    char item;
    if(top!=-1){
        item=st[top--];
        return item;
    }
}

int main(){
    char *e,exp[MAX];
    printf("\nEnter the expression:");
    scanf("%s",exp);
    e=exp;
    int x,f=0;
    while(*e!='\0'){
        if(*e=='('||*e=='{'||*e=='['){
            push(*e);
        }
        else{
            if(*e==')'){
                if((x=pop())!='('){
                    f++;
                    break;
                }
            }
            else if(*e=='}'){
                if((x=pop())!='{'){
                    f++;
                    break;
                }
            }
            else if(*e==']'){
                if((x=pop())!='['){
                    f++;
                    break;
                }
            }
        }
        e++;
    }

    //If stack is empty that means parentheses are balanced
    if(top==-1&&f==0){
        printf("\nBalanced parentheses");
    }
    else if(f!=0){
        printf("\nExpression not correct");
    }
    else{
        printf("\nUnbalanced parentheses");
    }
}