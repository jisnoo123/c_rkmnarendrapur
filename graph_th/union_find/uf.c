//Union and find
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
int n,re[MAX];
int gr[MAX][MAX],c=0;
struct node{
    int vertex;
    int representative;
    struct node *link;
};

struct node *set[MAX];

void input(){
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter 1 if edge is present otherwise 0:\n");
    //Making the adjacency matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(i!=j){
                printf("\nIs there any edge between vertices %d and %d ?: ",i,j);
                scanf("%d",&gr[i][j]);
            }
            else{
                gr[i][j] = 0;
            }
        }
    }
}

void makeset(int x){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->vertex = x;
    set[x] = t;
    t->link = NULL;
    //Initially everyone is a representative element of themselves
    set[x]->representative = x;
}

int findset(int u){
    // Assuming first element of the set to be the representative
    return set[u]->representative;
}

void union_vertices(int u, int v){
    if(set[u]->link==NULL && set[v]->link==NULL){
        //Both are single elements of their set
        //Then join v to u in a set
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->link = NULL;
        set[u]->link = p;
        p->vertex = v;
        p->representative = set[u]->representative; 
        set[v] = set[u]; 
    }
    else if(set[u]->link == NULL){
        // u is isolated. So join it with v
        struct node *p = set[v];
        while(p->link!=NULL){
            p=p->link;
        }

        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->vertex = u;
        set[u] = set[v];
        t->link = NULL;
        t->representative = v;
    }
    else{
        // v is isolated. So join it with u
        struct node *p = set[u];
        while(p->link!=NULL){
            p=p->link;
        }

        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->vertex = v;
        set[v] = set[u];
        t->link = NULL;
        t->representative = u;
    }
}

void connected_component(){
    for(int i=0 ;i<n; i++){
        //printf("Getting in here\n");
        makeset(i);
        struct node *t = (struct node *) malloc(sizeof(struct node));
        t->vertex = i;
        t->representative = i;
        set[i] = t; 
        t->link = NULL;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(i!=j){
                if(gr[i][j]==1){
                    //Edge is present between i and j
                    if(findset(i)!=findset(j)){
                        union_vertices(i,j);
                    }
                    else{
                        c++;
                    }
                }
            }
        }
    }
}

void result(){
    if(c!=0){
        printf("Circuit is present in the graph\n");
    }
    for(int i=0; i<n; i++){
        re[i] = set[i]->representative;
    }
    int cg=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==re[j]){
                cg++;
                break;
            }
        }
    }
    printf("No. of connected graphs: %d\n",cg);
}

void display_graph(){
    //Displays the adjacency matrix
    for(int i=0; i<n; i++){
        printf("\t %d ",i);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d",i);
        for(int j=0; j<=i; j++){
            printf("\t %d",gr[i][j]);
        }
        printf("\n");
    }
}

void display_rep_ele(){
    printf("\nRepresentative elements with vertex number underneath:\n");
    printf(" ");
    for(int i=0; i<n; i++){
        printf("  %d  ",set[i]->representative);
    }
    printf("\n ");
    for(int i=0; i<n; i++){
        printf(" (%d) ",i);
    }
    printf("\n");
}

int main(){
    input();
    display_graph();
    connected_component();
    display_rep_ele();
    result();
}