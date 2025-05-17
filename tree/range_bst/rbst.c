//Assuming that user does not give data input 10000 since its required for a certain manipulation. After that manipulation, user can input any number.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
    struct node *rthread;
};

struct node *root = NULL;
int num=0, last=10000;

struct node *create_node(){
    //Create a node with left and right child as NULL and return its address
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->lchild = NULL;
    t->rchild = NULL;
    t->rthread = NULL;
    return t;
}



void insert_bst(int x){
    //Insert a node in the BST
    int found = 0;
    struct node *prev = NULL;
    struct node *p = root;

    while(p!=NULL && found!=1){
        if(p->data == x){
            //Data already exists in the BST
            found = 1;
        }
        else if(p->data<x){
            prev = p;
            p = p->rchild;
        }
        else{
            prev = p;
            p = p->lchild;
        }
    }

    if(found == 1){
        printf("Data %d already exists in the BST\n", x);
    }
    else{
        struct node *t = create_node();
        t->data = x;
        if(root == NULL){
            root = t;
        }
        else if(prev->data<x){
            prev->rchild = t;
            t->rthread = prev->rthread;
            prev->rthread = t;
            if(root->data < x && x<last){
                root->rthread = t;
                last = x;
            }
        }
        else{
            prev->lchild = t;
            t->rthread = prev;
            if(root->data < x && x<last){
                root->rthread = t;
                last = x;
            }
        }
    }
}

struct node *inorder_successor(struct node *ptr){
    //Returns the inorder successor of the node pointed by ptr
    return ptr->rthread;
}

struct node *find_min(){
    //Returns the address of the minimum element in the BST
    struct node *p = root;

    while(p->lchild!=NULL){
        p = p->lchild;
    }

    return p;
}

void letsgo(){
    struct node *p = find_min();
    while(p!=NULL){
        printf("%d ", p->data);
        p = inorder_successor(p);
    }
    printf("\n");
}

void nodes_range(int low, int high){
    struct node *p = find_min();
    //p points to the lowest element
    //Make p point to the first element within the range
    while(p->data<low){
        p = inorder_successor(p);
    }

    //Now p points to the first element within the range

    int n=0; //Number of elements within the range

    while(p->data<=high){
        n++;
        p = inorder_successor(p);
    }

    printf("\nNumber of nodes within that range: %d", n);
}

void inorder(struct node *r){
    if(r!=NULL){
        inorder(r->lchild);
        printf("%d ",r->data);
        inorder(r->rchild);
    }
}

int main(){
    int ch,x,low,high;

    do{
        printf("\nEnter 1 to insert, 2 to search and 3 to display and 4 to see order and 5 to end:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\nEnter element:");
                scanf("%d",&x);
                insert_bst(x);
                break;
            
            case 2:
                printf("\nEnter lower bound of range:");
                scanf("%d",&low);
                printf("\nEnter upper bound of range:");
                scanf("%d",&high);
                nodes_range(low, high);
                break;
            
            case 3:
                inorder(root);
                break;
            
            case 4:
                letsgo();
                break;
            
            case 5:
                break;
        }
    }
    while(ch!=5);
}