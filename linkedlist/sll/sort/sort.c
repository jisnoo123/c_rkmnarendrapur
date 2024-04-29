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

void sort(struct node *head){
    for(struct node *i=head;i!=NULL;i=i->link){
        for(struct node *j=i->link;j!=NULL;j=j->link){
            if(i->data>j->data){
                int t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
}

int main(){
    entry(&h);
    printf("\nOriginal Linked List:\n");
    traverse(h);
    sort(h);
    printf("\nSorted Linked List:\n");
    traverse(h);
}