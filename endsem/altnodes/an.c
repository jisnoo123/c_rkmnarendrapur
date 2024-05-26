#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*h1=NULL,*h2=NULL;

void entry(){
    char c;
    int d;
    struct node *prev;
    do{
        printf("\nEnter element:");
        scanf("%d",&d);
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=d;
        new->link=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            prev->link=new;
        }
        prev=new;
        printf("\nEnter Y to continue and N to discontinue:");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c!='N');
}

void alternate(){
    struct node *p=head,*pre,*pro;
    int c=1;
    while(p!=NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=p->data;
        new->link=NULL;
        if(c%2==1){
            //Odd positioned
            if(h1==NULL){
                h1=new;
            }
            else{
                pro->link=new;
            }
            pro=new;
        }
        else if(c%2==0){
            //Even positioned
            if(h2==NULL){
                h2=new;
            }
            else{
                pre->link=new;
            }
            pre=new;
        }
        c++;
        p=p->link;
    }
}

void traverse(struct node *h){
    struct node *p=h;
    while(p!=NULL){
        printf(" %d ",p->data);
        p=p->link;
    }
}
int main(){
    entry();
    alternate();
    printf("\n1st LL:");
    traverse(h1);
    printf("\n2nd LL:");
    traverse(h2);
}