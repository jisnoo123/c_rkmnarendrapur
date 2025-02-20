#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int queue[MAX], top=-1;

struct node{
    struct node *lchild;
    struct node *rchild;
    int data;
};

struct node *getnode(){
    //Node creation
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->lchild = NULL;
    t->rchild = NULL;
}

/*Traversals*/

void preorder(struct node *root){
    //Preorder traversal
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct node *root){
    //Inorder traversal
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void postorder(struct node *root){
    //Postorder traversal
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

/*Tree creation*/
struct node *create_child(){
    struct node *child;
    child = getnode();
    child->lchild = NULL;
    child->rchild = NULL;

    printf("Enter data of the node: ");
    scanf("%d", &(child->data));
    printf("\n");
    return child;
}

void create_tree(struct node *root){
    printf("\nDo you want to create left child of %d? [Enter 1[y] or -1[n]]: ", root->data);
    int ch;
    scanf("%d", &ch);

    if(ch==1){
        //Create left child
        struct node *lc = create_child();
        root->lchild = lc;
        create_tree(lc);
    }

    printf("\nDo you want to create right child of %d? [Enter 1[y] or -1[n]]: ", root->data);
    scanf("%d", &ch);

    if(ch==1){
        //Create right child
        struct node *rc = create_child();
        root->rchild = rc;
        create_tree(rc);
    }
}

int count_nodes(struct node *root){
    //Counts the number of nodes in the tree
    if(root==NULL)
        return 0;
    else if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
        return 1 + (count_nodes(root->lchild) + count_nodes(root->rchild));
}

int count_external_nodes(struct node *root){
    //Counts the number of external nodes
    if(root==NULL)
        return 0;
    else if(root->lchild==NULL && root->rchild==NULL)
        return 1;
    else{
        return count_external_nodes(root->lchild) + count_external_nodes(root->rchild);
    }
}

int count_internal_nodes(struct node *root){
    //Counts the number of internal nodes in the tree
    if(root==NULL || (root->lchild==NULL && root->rchild==NULL))
        return 0;
    else if(root->lchild!=NULL || root->rchild!=NULL)
        return 1 + count_internal_nodes(root->lchild) + count_internal_nodes(root->rchild);
}

int main(){
    //Create the tree
    struct node *root = getnode();
    printf("Enter data of root:");
    scanf("%d",&(root->data));
    create_tree(root);

    //Perform operations as user wants
    int ch,ch2,v;
    
    do{
        printf("\nEnter 1 for traversal or 2 for other operations or 3 to end:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                //Traversal
                printf("Enter:\n1.Preorder\n2.Inorder\n3.Postorder\nYour choice:");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        //Preorder
                        printf("Preorder traversal:\n");
                        preorder(root);
                        break;
                    
                    case 2:
                        //Inorder
                        printf("Inorder traversal:\n");
                        inorder(root);
                        break;

                    case 3:
                        //Postorder
                        printf("Postorder traversal:\n");
                        postorder(root);
                        break;

                    default:
                        printf("Enter correctly\n");
                }
                break;
            
            case 2:
                //Other operations
                printf("Enter:\n1.Number of nodes\n2.Number of leaf nodes\n3.Number of external nodes\nYour choice:");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        //Number of nodes
                        v = count_nodes(root);
                        printf("Number of nodes: %d",v);
                        break;
                    
                    case 2:
                        //Number of leaf nodes
                        v = count_external_nodes(root);
                        printf("Number of external nodes: %d",v);
                        break;

                    case 3:
                        //Number of internal nodes
                        v = count_internal_nodes(root);
                        printf("Number of internal nodes: %d",v);
                        break;

                    default:
                        printf("Enter correctly\n");
                }
                break;
            
            case 3:
                //End
                break;
            default:
                printf("Enter correctly\n");
        }
    }
    while(ch!=3);
}