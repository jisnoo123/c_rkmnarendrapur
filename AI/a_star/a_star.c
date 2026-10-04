#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], heuristic[MAX], n;
int path[MAX];
int closed_path[MAX];
int open[MAX];
int closed[MAX];
int cinc=0, oinc=0;

struct Tuple{
    int cost_src;
    int cost_cl;
};

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

int min_fn(){
    // Return the vertex having the minimum f value
    int ele = -1;
    int min = 6000;
    for(int i=0; i<n; i++){
        if(min>open[i] && open[i]!=-1){
            min = open[i];
            ele = i;
        }
    }
    return ele;
}

void init(){
    //Initialization before A* search
    for(int i=0; i<n; i++){
        open[i] = -1;
        path[i] = -1;
        closed[i] = -1;
    }

    open[0] = 0;
    path[0] = -1; // nil parent of source
}

int is_empty(){
    // Finds out whether open is empty
    for(int i=0; i<n; i++){
        if(open[i]!=-1){
            return 0;
        }
    }
    return 1;
}

struct Tuple calc_cost(int v){
    // Calculate open path cost
    struct Tuple cost = {0, 0};

    int vt = v;

    while(path[v]!= -1){
        cost.cost_src += adj[v][path[v]];
        v = path[v];
    }
    
    v = vt;
    while(closed_path[v]!=-1){
        cost.cost_cl += adj[v][closed_path[v]];
        v = closed_path[v];
    }
        
    return cost;
}

void status(){
    printf("\nOpen: ");
    for(int i=0; i<n; i++){
        if(open[i]!=-1){
            printf("(%c, %d) ", i+65, open[i]);
        }
    }
    printf("\nClosed: ");
    for(int i=0; i<n; i++){
        if(closed[i]==1){
            printf("(%c, %c, %d) ", i+65, closed_path[i]+65, calc_cost(i).cost_cl);
        }
    }
}

void a_star(){
    init();
    
    // A* algorithm
    do{
        // Print status
        status();

        int vertex = min_fn();
        printf("\nVertex selected: %c", (vertex+65)); 
            
        if(vertex == n-1){
            printf("\nGoal state reached!");
            break;
        }

        for(int j=0; j<n; j++){
            if(adj[vertex][j]!=0){
                printf("\nVertex %c is adjacent", (j+65));

                if(closed[j]==1 && calc_cost(j).cost_cl>=adj[vertex][j]+calc_cost(vertex).cost_src){
                    // Remove j from closed and put it in open
                    printf("\nVertex %c is in CLOSED but cheaper path found so put it in OPEN and remove it from CLOSED");
                    closed[j] = 0;
                    closed_path[j] = -1;
                    open[j] = heuristic[j] + calc_cost(vertex).cost_src + adj[vertex][j];
                }                        
                else if(open[j]==1 && calc_cost(vertex).cost_src + adj[vertex][j] <= calc_cost(j).cost_src){
                    // Update j in open
                    printf("\nVertex %c is in OPEN but cheaper path found so update it in OPEN", j+65);
                    path[j] = vertex;
                    open[j] = heuristic[j] + calc_cost(vertex).cost_src + adj[vertex][j]; 
                }
                else if(open[j]==-1){
                    // Put j in open
                    printf("\nVertex %c is not in OPEN, so put it in OPEN", j+65);
                    open[j] = heuristic[j] + calc_cost(j).cost_src;
                }
                printf("\nHi!");
            }
            getchar(); 
        }
        open[vertex] = -1; //Remove vertex from OPEN
        
        // Put vertex in CLOSED
        closed[vertex] = 1;
        closed_path[vertex] = path[vertex]; 
    }
    while(!is_empty());    
}

void main(){
    input();
    display_matrix();

    printf("\n---Running A* algo---");
    a_star();
}
