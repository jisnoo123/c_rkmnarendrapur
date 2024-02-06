#include <stdio.h>
#include <stdlib.h>
struct node{
    int i;
    struct node *next;
};
struct node *head;

void push(int ch,int data){
    int no;
    struct node *ptr=(struct node *)(malloc(sizeof(struct node)));
    struct node *p=head;
        switch(ch){
            case 1:
                //first push
                ptr->i=data;                 
                if(head==NULL){
                    head=ptr;
                    ptr->next=NULL;
                }
                else{
                    ptr->next=head;
                    head=ptr;
                }
                break;

            case 2:
                //last push
                ptr->i=data;
                ptr->next=NULL;
                if(head==NULL){
                    head=ptr;   
                }
                else{
                    while(p->next!=NULL){
                        p=p->next;
                    }
                    p->next=ptr;
                }
                break;

            case 3:
                //pushing at desired node
                printf("Enter the node number after which you want to push:");
                scanf("%d",&no);
                int count=1;
                while(count<=no-1){
                    p=p->next;
                    count++;
                }
                struct node *t;
                t=p->next;
                p->next=ptr;
                ptr->next=t;
                ptr->i=data;
                break;

            default:
                printf("\n--Switch case error--");
    }
}

void delete(int ch){
    int item;
    int no;
    struct node *p=head;
    switch(ch){
        case 1:
            item=p->i;
            //first pop
            if(p->next==NULL){  
                free(head);
                head=NULL;
            }
            else{
                struct node *t;
                t=head;
                head=p->next;
                free(t);
            }
            printf("\nData is:%d",item);
            break;

        case 2:
            //last pop
            while(p->next->next!=NULL){
                p=p->next;
            }
            item=p->next->i;
            free(p->next);
            p->next=NULL;
            printf("\nData is:%d",item);
            break;

        case 3:
            //pop a desired node
            printf("\nEnter the node number you want to delete:");
            scanf("%d",&no);
            int count=1;
            while(count!=no-1){
                p=p->next;
                count++;
            }
            struct node *t;
            item=p->next->i;
            printf("\nData is:%d",item);
            t=p->next;
            p->next=p->next->next;
            free(t);
            break;

        default:
            printf("\n--Switch case error--");
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
        while(p->next!=NULL){
            printf("%d  ",p->i);
            p=p->next;
        }
        printf("%d  ",p->i);
    }
}

int main(){
    int inp,item;
    int c;
    do{
        printf("\nEnter 1 to insert, 2 for delete,3 for status and 4 to quit: ");
        scanf("%d",&inp);
        switch(inp){
            case 1:
                printf("\nEnter number of nodes: ");
                int n;
                scanf("%d",&n);
                int count=1;
                while(count<=n){
                    printf("\nEnter data:");
                    int d;
                    scanf("%d",&d);
                    printf("\nEnter 1 for first push,2 for end push and 3 for desired push: ");
                    scanf("%d",&c);
                    push(c,d);
                    count++;
                }
                break;
            case 2:
                printf("\nEnter 1 for first pop,2 for end pop and 3 for desired pop:");
                scanf("%d",&c);
                delete(c);
                break;
            case 3:
                status();
                break;

            case 4:
                break;

            default:
                printf("\n---Switch case error---");
        }
    }
    while(inp!=4);
}