#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int init[3][3] = {1, 2, 3, 4, -1, 5, 6, 7, 8};
int goal[3][3] = {1, -1, 2, 4, 5, 3, 6, 7, 8};

char opts[] = "UDRL";
int vacant[2];

struct node{
    struct node *next;
    struct node *parent;
    int a[3][3];
};

void input_matrix(int a[][3]){
    printf("Enter state:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("\nEnter element: ");
            scanf("%d", &a[i][j]);
        }
    }
}

void display_matrix(struct node *p){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(p->a[i][j]<0){
                printf("%d  ", p->a[i][j]);
            }
            else{
                printf(" %d  ", p->a[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n     ^\n     |\n\n");
}

int *find_vacant(struct node *p){
    // Finds the vacant position in the matrix (-1 for vacant)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(p->a[i][j]==-1){
                vacant[0] = i;
                vacant[1] = j;
                break;
            }
        }
    }
}

int check_bounds(struct node* p, char c){
    // Check whether the operation is even valid or not
    if(c=='U'){
        if(vacant[0]==1 || vacant[0]==2){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(c=='L'){
        if(vacant[1]==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(c=='D'){
        if(vacant[0]==0 || vacant[0]==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(c=='R'){
        if(vacant[1]==2){
            return 0;
        }
        else{
            return 1;
        }
    }
}

struct node* shuffle(struct node *p, char c){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    find_vacant(p);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            t->a[i][j] = p->a[i][j];
        }
    }

    if(c=='U'){
        t->a[vacant[0]][vacant[1]] = p->a[vacant[0]-1][vacant[1]];
        t->a[vacant[0]-1][vacant[1]] = -1;
    }
    else if(c=='D'){
        t->a[vacant[0]][vacant[1]] = p->a[vacant[0]+1][vacant[1]];
        t->a[vacant[0]+1][vacant[1]] = -1;
    }
    else if(c=='L'){
        t->a[vacant[0]][vacant[1]] = p->a[vacant[0]][vacant[1]-1];
        t->a[vacant[0]][vacant[1]-1] = -1;
    }
    else if(c=='R'){
        t->a[vacant[0]][vacant[1]] = p->a[vacant[0]][vacant[1]+1];
        t->a[vacant[0]][vacant[1]+1] = -1;
    }
    t->next = NULL;
    t->parent = p;
    return t;
}

struct node* production_rules(struct node *p, char c){
    // Returns the pointer to a newly created node if OK otherwise NULL
    if(check_bounds(p,c)==1){
        struct node *t = shuffle(p, c);
    }
    else{
        return NULL;
    }
}

int check_with_goal(struct node *p){
    struct node *ptr = p;
    int val=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(ptr->a[i][j]!=goal[i][j]){
                val = 1;
                break;
            }
        }
    }
    return val;
}

void BFS(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->parent = NULL;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            head->a[i][j] = init[i][j];
        }
    }

    while(head!=NULL){
        // Random number between 0 and 3
        for(int r=0; r<4; r++){
            struct node *t = production_rules(head, opts[r]);
            if(t!=NULL){  
                struct node *p = head;
                while(p->next!=NULL){
                    p = p->next;
                }
                p->next = t;
                int check_goal = check_with_goal(t);
                if(check_goal == 0){
                    printf("Successful!\nTrace:\n");
                    struct node *ptr = t;
                    while(ptr!=NULL){
                        display_matrix(ptr);
                        ptr = ptr->parent;
                    }
                    return;
                }            
            }
        }
        head = head->next;
    }

    printf("\nFailure!");
}

int main(){
    BFS();
}