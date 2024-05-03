#include <stdio.h>
#include <stdlib.h>

struct node{
    int c,e;
    struct node *link;
};
struct node *h1=NULL,*h2=NULL;
struct node *fh=NULL,*f=NULL;

void entry_p1(){
    struct node *t;
    int co,exp;
    char ch;
    do{
        printf("\nEnter coefficient:");
        scanf("%d",&co);
        printf("\nEnter exponent:");
        scanf("%d",&exp);
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->link=NULL;
        new->c=co;
        new->e=exp;
        if(h1==NULL){
            h1=new;
        }
        else{
            t->link=new;
        }
        t=new;

        printf("\nEnter Y to continue or N:");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch!='N');
}

void entry_p2(){
    struct node *t;
    int co,exp;
    char ch;
    do{
        printf("\nEnter coefficient:");
        scanf("%d",&co);
        printf("\nEnter exponent:"); 
        scanf("%d",&exp);
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->link=NULL;
        new->c=co;
        new->e=exp;
        if(h2==NULL){
            h2=new;
        }
        else{
            t->link=new;
        }
        t=new;

        printf("\nEnter Y to continue or N:");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch!='N');
}

void mult(){
    struct node *p=h1;
    struct node *q=h2;
    int flag=0,cf,ex;
    while(p!=NULL){
        q=h2;
        while(q!=NULL){
            cf=p->c*q->c;
            ex=p->e+q->e;
            struct node *ptr=fh;
            while(ptr!=NULL){
                if(ptr->e==ex){
                    flag=1;
                    ptr->c=ptr->c+cf;
                }        
                ptr=ptr->link;
            }
            if(flag==0){
                struct node *new=(struct node *)malloc(sizeof(struct node));
                new->c=cf;
                new->e=ex;
                new->link=NULL;
                if(fh==NULL){
                    fh=new;
                    f=new;
                }
                else{
                    f->link=new;
                    f=new;
                }
            }
            q=q->link;
        }
        p=p->link;
    }

}

void traverse(struct node *head){
    if(head==NULL){
        printf("\nEmpty Linked List");
    }
    else{
        struct node *t;
        t=head;
        while(t->link!=NULL){
                printf("%d x^%d+",t->c,t->e);
                t=t->link;
        }
        printf("%d x^%d",t->c,t->e);
    }
}

int main(){
    printf("\nFirst Polynomial\n");
    entry_p1();
    printf("\nSecond Polynomial\n");
    entry_p2();
    printf("\nFirst polynomial\n");
    traverse(h1);
    printf("\nSecond polynomial\n");
    traverse(h2);
    mult();
    printf("\nResult:");
    traverse(fh);
}