#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *head;

void create(int item){
    struct node *ad;
    ad=(struct node*)(malloc(sizeof(struct node)));
    ad->data=item;
    ad->link=NULL;
    if(head==NULL){
        head=ad;
    }
    else{
        struct node *p;
        p=head;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=ad;
    }
}

void delete(int n){
    if(head==NULL){
        printf("\nLinked list empty");
    }
    else{
        struct node *p=head;
        while(p->link->data!=n){
            p=p->link;
        }
        struct node *sl=p;
        struct node *des=p->link;
        sl->link=des->link;
        free(des);
    }
}

void status(){
    if(head==NULL){
        printf("\nNo elements");
    }
    else{
        struct node *p;
        p=head;
        printf("\nYour elemets are:\n");
        while(p->link!=NULL){
            printf("%d  ",p->data);
            p=p->link;
        }
        printf("%d  ",p->data);
    }
}

void firstpush(int item){
    struct node*p=head;
    if(head==NULL){
        create(item);
    }    
    else{
        struct node *ad;
        ad=(struct node*)(malloc(sizeof(struct node)));
        ad->data=item;
        ad->link=head;
        head=ad;
    }
}
int main(){
    int inp,item;
    do{
        printf("\nEnter 1 to insert, 2 for status,3 to delete,4 for first push and 5 to stop: ");
        scanf("%d",&inp);
        switch(inp){
            case 1:
                printf("\nEnter number of nodes: ");
                int n;
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("\nEnter data: ");
                    int item;
                    scanf("%d",&item);
                    create(item);
                }
                break;
            case 2:
                status();
                break;
            case 3:
                printf("\nEnter data to delete:");
                scanf("%d",&item);
                delete(item);
                break;
            case 4:
                printf("\nEnter element to push:");
                scanf("%d",&item);
                firstpush(item);
                break;
            default:
                printf("\n---Switch case error---");
        }
    }
    while(inp!=5);
}