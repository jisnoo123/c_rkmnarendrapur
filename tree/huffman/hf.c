//Huffman Tree Creation
//This code is crashing. I am not able to find the bug
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int w[MAX], n, s[MAX]; //s[]:Symbols, w[]: frequencies

struct node{
    char data;
    int freq;
    struct node *lchild;
    struct node *rchild;
};

struct node *a[MAX]; // Array of pointers

struct node *create_node(){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->rchild = NULL;
    t->lchild = NULL;
    t->data = -1;
    return t;
}

void input(){
    printf("Enter number of symbols:");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("\nEnter symbol:");
        scanf("%d",&s[i]);
        printf("\nEnter its weight:");
        scanf("%d",&w[i]);
        printf("\n");
    }
}

void sort(int m){
    //Sort a[m...n-1] w.r.t frequencies of the symbols

    for(int i=m+1; i<n; i++){
        int k = a[i]->freq;
        struct node *kad = a[i]; //Address of k
        int j = i-1;

        while(a[j]->freq > k && j>=m){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = kad;
    }
}

struct node *huffman_create(){
    // First store each symbol in a node and each address of node in an array of pointers A[]
    for(int i=0; i<n; i++){
        struct node *t = create_node();
        t->data = s[i];
        t->freq = w[i];
        a[i] = t; // Store the node's address in the array of pointers
    }
    printf("Hi!!!");
    int i=0;
    
    while(i<n-1){
        sort(i); // Sort a[i...n-1] wrt the frequencies

        struct node *t = create_node();
        t->freq = a[i]->freq + a[i+1]->freq;
        t->data = -1; 
        t->lchild = a[i];
        t->rchild = a[i+1];
        a[i+1] = t;
    }
    
    printf("hello!");
    return a[n-1];
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ", root->freq);
        inorder(root->rchild);
    }
}

int main(){
    input();
    struct node *root = huffman_create();
    printf("\nInorder traversal of Huffman tree is:");
    inorder(root);
}