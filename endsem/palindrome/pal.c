//To check whether the contents of a linked list palindrome or not
#include <stdlib.h>
#include <stdio.h>

struct node{
    char data;
    struct node *link;
};
struct node *head=NULL;

void entry(){
    char c,d;
    struct node *prev;
    do{
        printf("\nEnter element:");
        scanf("%c",&d);
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

void traverse(struct node *h){
    struct node *p=h;
    while(p!=NULL){
        printf(" %c ",p->data);
        p=p->link;
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

void pal(){
    struct node *revh=reverse(head);
    printf("\nReverse:");
    traverse(revh);
    struct node *p=head,*q=revh;
    int flag=0;
    while(p!=NULL && q!=NULL){
        if(p->data!=q->data){
            flag++;
            break;
        }
        p=p->link;
        q=q->link;
    }

    if(flag==0){
        printf("\nPalindrome");
    }
    else{
        printf("\nNot Palindrome");
    }
}

int main(){
    entry();
    printf("\nOriginal LL:");
    traverse(head);
    pal();
}