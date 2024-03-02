#include <stdio.h>
#include <ctype.h>
#define MAX 100
int top=-1;
char stack[MAX];

void push(char *s){
    stack[++top]=*s;
}

char pop(){
    char c;
    if(top==-1){
        printf("\n--Done--");
    }
    else{
        c=stack[top--];
        return c;   
    }
}

int priority(char *s){
    char x=*s;
    //Checking priority 
    if(x=='('){
        return 0;
    }
    else if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
}

int main(){
    char exp[MAX],c;
    int n;
    printf("Enter number of characters in the expression:");
    scanf("%d",&n);
    printf("\nEnter your expression:");
    scanf("%s",exp);

    char *e=exp;
    
    while((*e)!='\0'){
        if(isalnum(*e)){
            printf("%c ",*e);
        }
        else if((*e)=='('){
            push(e);
        }
        else if((*e)==')'){
            while((c=pop())!='('){
                printf("%c ",c);
            }
        }
        else{//for other operators
            if(priority(&stack[top])<priority(e)){
                push(e);
            }
            else{
                while(priority(&stack[top])>priority(e)){
                    printf("%c ",pop());
                }
                push(e);
            }
        }
        e++;
    }
    while(top!=-1){
        char ch;
        if(pop()!='('){
            top++;
            printf("%c ",pop());
        }
    }
}