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

void add(){
    struct node *p=h1;
    struct node *q=h2;

    while((p!=NULL)&&(q!=NULL)){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->link=NULL;
        
        if(fh==NULL){
            fh=new;
            f=new;
        }
        else{
            f->link=new;
            f=new;
        }

        if((p->e)>(q->e)){
            new->c=p->c;
            new->e=p->e;
            p=p->link;
        }
        else if(p->e<q->e){
            new->c=q->c;
            new->e=q->e;
            q=q->link;
        }
        else{
            new->c=q->c+p->c;
            new->e=q->e;
            p=p->link;
            q=q->link;
        }

    }

    while(p!=NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->link=NULL;
        f->link=new;
        f=new;
        new->c=p->c;
        new->e=p->e;
        p=p->link;
    }

    while(q!=NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->link=NULL;
        f->link=new;
        f=new;
        new->c=q->c;
        new->e=q->e;
        q=q->link;
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
            if(t->link->c<0){
                printf("%d x^%d",t->c,t->e);
            }
            else{
                printf("%d x^%d+",t->c,t->e);
            }
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
    add();
    printf("\nResult:");
    traverse(fh);
}