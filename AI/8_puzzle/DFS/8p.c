#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int init[3][3] = {1, 2, 3, 4, -1, 5, 6, 7, 8};
int goal[3][3] = {1, -1, 2, 4, 5, 3, 6, 7, 8};
int state[3][3], vacant[2];

char opts[] = "UDRL";

void assign_matrix(int a[][3], int b[][3]){
    for(int *p=&a[0][0], *q=&b[0][0]; p<=&a[3][3]; p++, q++){
        //printf("%d ", *q);
        *p = *q;
    }
}

void display_matrix(int a[][3]){
    for(int (*p)[3] = a; p < a + 3; p++){
        for(int *q = &p[0][0], i=1; i<=3; q++, i++){
            printf("%d\t", *q);
        }
        printf("\n");
    }
}

void find_vacant(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(state[i][j]==-1){
                vacant[0] = i;
                vacant[1] = j;
                return;
            }
        }
    }
}

int is_goal(){
    int flag = 1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(state[i][j]!=goal[i][j]){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void change_opts(int pos){
    for(int i=pos+1; i<=strlen(opts); i++){
        opts[i-1] = opts[i];
    }
}

int check_bounds(char ch){
    find_vacant();

    if(ch == 'U' && (vacant[0] == 0)){
        return 0;
    }
    else if(ch == 'D' && (vacant[0] == 2)){
        return 0;
    }
    else if(ch == 'L' && (vacant[1] == 0)){
        return 0;
    }
    else if(ch == 'R' && (vacant[1] == 2)){
        return 0;
    }

    return 1;
}

int shuffle(){
    // Return 4 if state is goal, 3 if no opts available, 2 if out of bounds, 1 if shuffle successful
    //printf("\nBro?");
    if(is_goal()==1){
        //printf("\n4");
        return 4;
    }

    srand(time(NULL));
    int len = strlen(opts);
    printf("\nL: %d", len);
    if(len>0){
        int pos = rand()%len;
        printf("\nOpts: %s", opts);
        char ch = opts[pos];
        change_opts(pos);
        printf("\n\t|\n\t|(%c)\n\tV\n", ch);

        if(check_bounds(ch) == 1){
            if(ch == 'U'){
                state[vacant[0]][vacant[1]] = state[vacant[0]-1][vacant[1]];
                state[vacant[0]-1][vacant[1]] = -1;
            }
            else if(ch == 'L'){
                state[vacant[0]][vacant[1]] = state[vacant[0]][vacant[1]-1];
                state[vacant[0]][vacant[1]-1] = -1;
            }
            else if(ch == 'R'){
                state[vacant[0]][vacant[1]] = state[vacant[0]][vacant[1]+1];
                state[vacant[0]][vacant[1]+1] = -1;
            }
            else if(ch == 'D'){
                state[vacant[0]][vacant[1]] = state[vacant[0]+1][vacant[1]];
                state[vacant[0]+1][vacant[1]] = -1;
            }
            //printf("\n1");
            return 1;
        }
        else{
            //printf("\n2");
            return 2;
        }
    }
    else{
        return 3;
    }
}

void DFS(){
    assign_matrix(state,init);
    printf("Initial state:\n");
    display_matrix(state);
    printf("\nGoal state:\n");
    display_matrix(goal);

    printf("\nComputation:\n");
    int res;

    do{
        res = shuffle();
        if(res == 1){
            display_matrix(state);
        }
    }
    while(res == 1);
        
    if(res == 4){
        display_matrix(state);
        printf("\nSuccessful!");
    }
    else if(res == 3){
        printf("\nFailure! No available options");
    }
    else if(res == 2){
        printf("\nFailure! Out of Bounds");
    }
}

int main(){
    DFS();
}