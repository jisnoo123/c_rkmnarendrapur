#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
int a,b;
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

void dis(){
    int c=0;
    printf("\nEnter the two data bet which distance needs to be computed:");
    scanf("%d%d",&a,&b);
    struct node *p=head;
    while(p->data!=a){
        p=p->link;
    }
    //Stopped at a
    p=p->link;
    while(p->data!=b){
        c++;
        p=p->link;
    }
    printf("\nDistance:%d",c);
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
    printf("\nOriginal LL:");
    traverse(head);
    dis();
}