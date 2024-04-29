#include <stdio.h>
#include <stdlib.h>
//Merging two linked lists
struct node{
    int data;
    struct node *link;
};
struct node *h1=NULL,*h2=NULL;
void entry(struct node **h){
    int n,d;
    printf("\nEnter number of elements in the linked list:");
    scanf("%d",&n);
    struct node *new,*t;
    for(int i=0;i<n;i++){
        printf("\nEnter data:");
        scanf("%d",&d);
        new=(struct node *)malloc(sizeof(struct node));
        new->data=d;
        new->link=NULL;
        if(*h==NULL){
            *h=new;
        }
        else{
            t->link=new;
        }
        t=new;
    }
}

void traverse(struct node *h){
    if(h==NULL){
        printf("\nEmpty linked list");
    }
    else{
        struct node *p=h;
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->link;
        }
    }
}

void merge(){
    struct node *p=h1;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=h2;
}

int main(){
    printf("\nFirst linked list:");
    entry(&h1);
    printf("\nSecond linked list:");
    entry(&h2);
    printf("\nFirst linked list:\n");
    traverse(h1);
    printf("\nSecond linked list:\n");
    traverse(h2);
    merge();
    printf("\nMerged linked list:");
    traverse(h1);
}