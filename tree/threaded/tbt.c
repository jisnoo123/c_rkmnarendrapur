#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
    int rthread; //1:thread , 0:link
};

struct node *head = NULL;

struct node *create_node(){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->lchild=NULL;
    t->rchild=NULL;
    t->rthread=0; //Indicates it is a link
    return t;
}

void insert_left_child(struct node *x){
    //Insert as a left child of node pointed by x
    struct node *z = create_node();
    printf("\nEnter data:");
    scanf("%d",&z->data);
    x->lchild = z;
    z->rthread = 1;
    z->rchild = x;
    z->lchild = NULL;
}

void insert_right_child(struct node *x){
    //Insert as a right child of node pointed by x
    struct node *z = create_node();
    printf("\nEnter data:");
    scanf("%d",&z->data);
    x->rthread = 0;
    z->rchild = x->rchild;
    x->rchild = z;
    z->rthread = 1;
}

void creation(struct node *root){
    //Creates a threaded binary tree
    int ch;
    printf("\nDo you want to create left child of %d ? [Enter 1[y] or -1[n]]: ",root->data);
    scanf("%d",&ch);

    if(ch==1){
        insert_left_child(root);
        creation(root->lchild);
    }

    printf("\nDo you want to create right child of %d ? [Enter 1[y] or -1[n]]: ",root->data);
    scanf("%d",&ch);

    if(ch==1){
        insert_right_child(root);
        creation(root->rchild);
    }
} 

struct node *inorder_successor(struct node *p){
    //Find the inorder successor of the node pointed by p
    struct node *x = p->rchild;

    if(x->rthread==0){
        while(x->lchild!=NULL){
            x = x->lchild;
        }
    }

    return x;
}

void threaded_inorder(){
    struct node *p = head;
    
    do{
        p = inorder_successor(p);
        if(p!=head)
            printf("%d ", p->data);
    }
    while(p!=head);
}

int main(){
    //Create the head
    head = create_node();
    head->data = -1;
    head->rchild = head;
    
    //Create root
    struct node *root = create_node();
    //Link head with root as its left child
    head->lchild = root;

    printf("Enter data of root:");
    scanf("%d",&(root->data));

    //Create the threaded tree
    creation(root);

    printf("Inorder traversal:\n");
    threaded_inorder();
}