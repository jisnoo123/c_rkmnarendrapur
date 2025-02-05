#include <stdlib.h>
#include <stdio.h>
//Circular Linked List
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;

void entry(){
    int n,d;
    printf("\nEnter number of elements in the linked list:");
    scanf("%d",&n);
    struct node *new,*t;
    for(int i=0;i<n;i++){
        printf("\nEnter data:");
        scanf("%d",&d);
        new=(struct node *)malloc(sizeof(struct node));
        new->data=d;
        new->link=head;
        if(head==NULL){
            head=new;
        }
        else{
            t->link=new;
        }
        t=new;
    }
}

void traverse(){
    if(head==NULL){
        printf("\nEmpty linked list");
    }
    else{
        struct node *p=head;
        while(p->link!=head){
            printf("%d ",p->data);
            p=p->link;
        }
        printf("%d ",p->data);
    }
}

int main(){
    entry();
    traverse();
}