#define MAX 100
#include <stdlib.h>
#include <stdio.h>

struct node *ad[MAX]; int size, top=-1;
char pf[MAX];

struct node{
    char data;
    struct node *lc;
    struct node *rc;
};

struct node *getnode(){
    struct node *x = (struct node *) malloc(sizeof(struct node));
    x->lc = NULL;
    x->rc = NULL;
    return x;
}

void push(struct node *n){
    ad[++top] = n;
}

struct node *pop(){
    if(top == -1){
        printf("\nEnd of stack\n");
    }
    else{
        return ad[top--];
    }
}

void inorder(struct node *root){
    //Inorder traversal
    if(root!=NULL){
        inorder(root->lc);
        printf("%c ", root->data);
        inorder(root->rc);
    }
}

struct node *create(){
    int i = 0;

    while(i<size){
        char c = pf[i];
        
        if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8'|| c=='9'){
            //Operand
            struct node *x = getnode();
            x->data = c;
            push(x);
        }
        else if(c=='+'||c=='-'||c=='*'){
            //Operator (Considering only Binary operators) 
            struct node *x = getnode();
            x->data = c;

            struct node *b = pop();
            struct node *a = pop();

            x->lc = a;
            x->rc = b;
            push(x);
        }
        i++;
    }

    return pop();
}

void display_expn_tree(struct node *root){
    //Display the expression tree
    inorder(root);
}

int evaluate(struct node *root){
    struct node *p = root;
    if(p!=NULL){
        struct node *lp = p->lc;
        struct node *rp = p->rc;
        int t1, t2;

        if(lp->data=='1' || lp->data=='2' || lp->data=='3'){
            t1 = lp->data;
        }
        else{
            t1 = evaluate(lp);
        }

        if(rp->data=='1' || rp->data=='2' || rp->data=='3'){
            t2 = rp->data;
        }
        else{
            t2 = evaluate(rp);
        }

        char opt = p->data;
        int value;
        //Compute the value

        if(opt == '+')
            value = ((int)(t1)-48) + ((int)(t2)-48);
        else if(opt == '-')
            value = ((int)(t1)-48) - ((int)(t2)-48);
        else if(opt == '*')
            value = (((int)(t1))-48) * (((int)(t2))-48);
        
        return value;
    }
}

int main(){
    printf("Enter number of characters in the expression:");
    scanf("%d", &size);
    fflush(stdin);

    printf("Enter expression:");
    scanf("%s",pf);

    struct node *root = create();
    printf("Inorder traversal of the expression tree:\n");
    display_expn_tree(root);
    printf("\nEvaluated value:%d", evaluate(root));
    printf("\n");
}