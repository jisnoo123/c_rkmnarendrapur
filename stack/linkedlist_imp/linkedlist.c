#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;

void push(int item){
    struct node *p= (struct node *)(malloc(sizeof(struct node)));
    if(p==NULL){
        printf("Error of malloc");
        return;
    }
    p->data=item;
    p->link=head;
    head=p;
}

int pop(){
    int item;
    struct node *t;
    if(head==NULL){
        printf("Underflow");
        return -1;
    }
    item=head->data;
    t=head;
    head=head->link;
    free(t);
    return item;
}

int main(){
    int inp;
    do{
        printf("\nEnter 1 to insert, 2 to delete and 3 to stop: ");
        scanf("%d",&inp);
        if(inp==1){
            int item;
            printf("\nEnter data");
            scanf("%d",&item);
            push(item);
        }
        else if(inp==2){
            int item=pop();
            printf("\n%d",item); 
        }
    }
    while(inp!=3);
}