#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *lchild;
    struct node *rchild;
    int data;
};

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
struct node *getnode(){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->lchild = NULL;
    t->rchild = NULL;
}

struct node *create_child(){
    struct node *child;
    child = getnode();
    child->lchild = NULL;
    child->rchild = NULL;

    printf("Enter data:");
    scanf("%d", &(child->data));
    return child;
}

void create_tree(struct node *root){
    printf("Do you want to create left child of %d? [1 or -1]: ", root->data);
    int ch;
    scanf("%d", &ch);

    if(ch==1){
        //Create left child
        struct node *lc = create_child();
        root->lchild = lc;
        create_tree(lc);
    }

    printf("Do you want to create right child of %d? [1 or -1]: ", root->data);
    scanf("%d", &ch);
    if(ch==1){
        //Create right child
        struct node *rc = create_child();
        root->rchild = rc;
        create_tree(rc);
    }
}

int main(){
    struct node *root = getnode();
    printf("Enter data of root:");
    scanf("%d",&(root->data));

    create_tree(root);

    printf("Preorder traversal:");
    preorder(root);
}