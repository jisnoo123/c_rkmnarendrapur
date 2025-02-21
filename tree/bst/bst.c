#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *root = NULL;

struct node *create_node(){
    struct node *t = (struct  node *)malloc(sizeof(struct node));
    t->rchild = NULL;
    t->lchild = NULL;
    return t;
}

void insert_bst(struct node *rt, int x){
    //Inserts x into the BST pointed by rt
    int found = 0;
    struct node *prev = NULL;
    struct node *p = rt;

    while(found==0 && p!=NULL){
        if(p->data == x){
            found = 1;
        }
        else{
            if(p->data<x){
                prev = p;
                p=p->rchild;
            }
            else{
                prev = p;
                p=p->lchild;
            }
        }
    }
    
    if(root==NULL){
        root = create_node();
        root->data = x;
    }
    else{
        if(found == 1){
            //Data already exists
            printf("Data exists in the BST\n");    
        }
        else{
            struct node *z = create_node(); //Creating a new node to insert x
            z->data = x;
            if(prev->data<x){
                prev->rchild = z;
            }
            else{
                prev->lchild = z;
            }
        }
    }
}

void inorder(struct node *rt){
    //Inorder traversal
    if(rt!=NULL){
        inorder(rt->lchild);
        printf("%d ", rt->data);
        inorder(rt->rchild);
    }
}

struct node *search_bst(struct node *rt, int x){
    int found = 0;
    struct node *p = rt;
    struct node *prev = NULL;

    while(found==0 && p!=NULL){
        if(p->data == x){
            printf("%d Found", x);
            found = 1;
        }
        else{
            if(p->data<x){
                prev = p;
                p = p->rchild;
            }
            else{
                prev = p;
                p = p->lchild;
            }
        }
    }

    if(found  == 0){
        //Not found
        return NULL;
    }
}

void creation(){
    int d, ch;
    do{
        printf("Do you want to insert data? [1[y] or -1[n]]: ");
        scanf("%d",&ch);
        if(ch==1){
            printf("\nEnter data to be inserted:");
            scanf("%d",&d);
            insert_bst(root, d);
        }
    }
    while(ch!=-1);
}

int main(){
    creation();
    printf("Inorder traversal:\n");
    inorder(root);
}