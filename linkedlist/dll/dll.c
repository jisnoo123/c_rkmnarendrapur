//Doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev,*front;
};
struct node *head=NULL;

void push(int ch){
    int d;
    printf("\nEnter data:");
    scanf("%d",&d);
    int pdel;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->front=NULL;
    new->data=d;
    struct node *p=head;
    if(head==NULL){
        head=new;
        new->prev=NULL;
    }
    else{
        int c=1;
        switch(ch){
            case 1:
                //at the beginning 
                new->front=head;
                head->prev=new;
                head=new;
                new->prev=NULL;
                break;
            
            case 2:
                //at the end
                while(p->front!=NULL){
                    p=p->front;
                }
                p->front=new;
                new->prev=p;
                new->front=NULL;
                break;

            case 3:
                //at any desired location
                printf("\nEnter position of the node to be inserted:");
                scanf("%d",&pdel);
                c=1;
                while(c!=pdel-1){
                    c++;
                    p=p->front;
                }
                new->front=p->front;
                p->front->prev=new;
                p->front=new;
                new->prev=p;
                break;
        }
    }
}

void delete(int ch){
    struct node *p,*t;
    int pdel,c;
    switch(ch){
        case 1:
            //Delete the beginning
            printf("\nDeleting %d",head->data);
            p=head;
            head=head->front;
            head->prev=NULL;
            free(p);
            break;

        case 2:
            //delete the end
            p=head;
            while(p->front->front!=NULL){
                p=p->front;
            }
            printf("\nDeleting %d",p->front->data);
            free(p->front);
            p->front=NULL;
            break;
        
        case 3:
            //Delete desired
            p=head;
            printf("\nEnter position of the node to be deleted:");
            scanf("%d",&pdel);
            c=1;
            while(c!=pdel-1){
                c++;
                p=p->front;
            }
            printf("\nDeleting %d",p->front->data);
            t=p->front;
            p->front=p->front->front;
            p->front->prev=p;
            free(t);
            break;
    }
}

void status(){
    struct node *p=head;
    if(head==NULL){
        printf("\nEmpty Linked List");
    }
    else{
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->front;
        }
    }
}

int main(){
    int ch;
    do{
        printf("\nEnter 1 to push, 2 to delete and 3 to traverse and 4 to end:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                //Push
                printf("\nEnter 1 to push at the beginning, 2 at the end and 3 for desired:");
                scanf("%d",&ch);
                push(ch);
                break;
            
            case 2:
                //Delete
                printf("\nEnter 1 to delete the beginning, 2 at the end and 3 for desired:");
                scanf("%d",&ch);
                delete(ch);
                break;
            
            case 3:
                status();
                break;
            
            case 4:
                break;
        }
    }
    while(ch!=4);
}