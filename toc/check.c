#include <stdlib.h>
#include <stdio.h>
#define MAX 100
struct node{
    int data;
    struct node *link;
};

struct node *heads[MAX]; // Array of pointers 

struct node *create_node(int d){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = d;
    t->link = NULL;
    return t;
}

int main(){
    int head_index = 0;

    heads[head_index] = create_node(1);
    head_index++;
    heads[head_index] = create_node(2);
    head_index++;
    heads[head_index] = (struct node *)(-2);

    for(int i=0; i<3; i++){
        printf("%u ", heads[i]);
    }
}