#include <stdio.h>
#include <stdlib.h>
//Merging two linked lists
struct node{
    int data;
    struct node *link;
};
struct node *h=NULL;

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

struct node *reverse(struct node *h){
    struct node *front=NULL,*prev=NULL,*cur=h;
    while(cur!=NULL){
        front=cur->link;
        cur->link=prev;
        prev=cur;
        cur=front;
    }
    return prev;
}

int main(){
    entry(&h);
    printf("\nOriginal linked list:\n");
    traverse(h);
    h=reverse(h);
    printf("\nReversed Linked List:\n");
    traverse(h);
}