#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], heuristic[MAX], n;
int fringe[MAX];
int closed[MAX];
int cinc=0;
int path_b[MAX];
int p_b = 0;

void input(){
    printf("\nEnter number of vertices in the graph:");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nHeuristic of %c vertex:", (i+65));
        scanf("%d", &heuristic[i]);
        for(int j=i+1; j<n; j++){
            //printf("\ni:%d j:%d", i, j);
            printf("\n%c -> %c Cost: ",(i+65), (j+65));
            scanf("%d", &adj[i][j]);
        }
    }
    //Copy the symmetric part
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            adj[i][j] = adj[j][i];
        }
    }
}

void display_matrix(){
    printf("\nCost matrix of the graph:\n");
    printf("  ");
    for(int i=0; i<n; i++){
        printf("%c  ", (i+65));
    }

    for(int i=0; i<n; i++){
        printf("\n%c ", (i+65));
        for(int j=0; j<n; j++){
            printf("%d  ", adj[i][j]);         
        }
        printf("\n");
    }
}

void init(){
    for(int i=0; i<n; i++){
        fringe[i] = -1;
    }
    // Start with the initial state
    closed[0] = 0;
    cinc = 1;
    fringe[0] = heuristic[0];
}

int remove_first(){
    // Return the vertex having the least heuristic value in fringe
    int min = 6000;
    int ele = -1;
    for(int i=0; i<n; i++){
        if(fringe[i]<min && fringe[i]!=-1){
            min = heuristic[i];
            ele = i;
        }
    }
    fringe[ele] = -1; // After removal
    return ele; 
}

int is_empty(){
    for(int i=0; i<n; i++){
        if(fringe[i]!=-1){
            return 0;
        }
    }
    return 1;
}

int in_closed(int v){
    for(int i=0; i<cinc; i++){
        if(v == closed[i]){
            return 1;
        }
    }
    return 0;
}

void print_fringe(){
    for(int i=0; i<n; i++){
        if(fringe[i]!=-1){
            printf("(%c, %d) ", i+65, fringe[i]);
        }
    }
}

void BFS(){
    do{
        printf("\n\nFringe:");
        print_fringe();
        int vertex = remove_first();
        printf("\nVertex selected: %c", (vertex+65)); 
        path_b[p_b] = vertex;
        p_b++;
        if(vertex == n-1){
            printf("\n\nGoal state reached!");
            break;
        }
        for(int j=0; j<n; j++){
            if(adj[vertex][j]!=0 && !in_closed(j)){
                printf("\nAdjacent vertex %c with heuristic %d added to fringe", j+65, heuristic[j]);
                fringe[j] = heuristic[j];
                closed[cinc] = j;
                cinc++;
            }
        }  
    }
    while(!is_empty());
    
    int path_cost = 0;
    printf("\nPath for BFS: ");
    for(int i=0; i<p_b; i++){
        printf("%c ", (path_b[i]+65));
        path_cost+=adj[path_b[i]][path_b[i+1]];
    }
    printf("\nPath cost: %d", path_cost);
}

int main(){
    input();
    display_matrix();
    init();

    printf("\n----Running Best First Search------");
    BFS();
}
