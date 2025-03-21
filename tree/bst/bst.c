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

int insuc(struct node *p){
    // Find the inorder successor of the node pointed by p
    struct node *q = p->rchild;
    while(q->lchild!=NULL){
        q = q->lchild;
    }
    return(q->data);
}

void delete_bst(struct node *root, int x){
    /* delete x from BST pointed by root*/
    int found = 0;
    struct node *p = root;
    struct node *prev = NULL;

    while(p!=NULL && found==0){
        if(p->data == x){
            //Found
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

    if(found == 0){
        //Not found
        printf("%d not found in tree\n",x);
    }
    else{
        int c;
        if(p->lchild == NULL && p->rchild == NULL){
            //Leaf node
            c = 1;
        }
        else if(p->lchild!=NULL && p->rchild!=NULL){
            //Node to be deleted has two children
            c = 3;
        }
        else{
            //Node to be deleted has one child
            c = 2;
        }

        //Perform the manipulations for deletion

        if(c == 1){
            if(prev->lchild==p){
                //Node to be deleted is in the left of prev
                free(p);
                prev->lchild = NULL;
            }
            else{
                //Node to be deleted is in the right of prev
                free(p);
                prev->rchild = NULL;
            }
        }
        else if(c == 2){
            if(prev->lchild==p){
                if(p->rchild==NULL){
                    //p has a right child
                    prev->lchild = p->lchild;
                }
                else{
                    //p has a right child
                    prev->lchild = p->rchild;
                }
            }
            else{
                if(p->rchild==NULL){
                    //p has a right child
                    prev->rchild = p->lchild;
                }
                else{
                    //p has a right child
                    prev->rchild = p->rchild;
                }
            }
        }
        else{
            int d = insuc(p);
            delete_bst(root, d);
            p->data = d;
        }
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
    int ch,d;
    do{
        printf("Enter 1 for inorder traversal, 2 for insertion, 3 for deletion, 4 to end:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                inorder(root);
                break;
            
            case 2:
                printf("Enter data to be inserted:");
                scanf("%d",&d);
                insert_bst(root, d);
                break;
            
            case 3:
                printf("Enter data to be deleted:");
                scanf("%d",&d);
                delete_bst(root, d);
                break;
            
            case 4:
                break;
        }
    }
    while(ch!=4);
}