#include <stdio.h>
#include <string.h>

int inp[3][3] = {1, 2, 3, 5, 6, -1, 7, 8, 4}, goal[3][3] = {1, 2, 3, 5, 8, 6, -1, 7, 4};
char moves[5] = {'R', 'L', 'U', 'D'};
int pos[2] = {-1,-1};
char avail_moves[5];

void input(){
    printf("\nEnter input matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &inp[i][j]);
        }
    }

    printf("\nEnter goal matrix:\n"); 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &goal[i][j]);
        }
    }
}

int calc_heuristic(int (*p)[3]){
    // Here heuristic is the number of mismatched tiles
    int h = 0;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(p[i][j]!=goal[i][j])
                h++;
        }
    }
    return h;
}

void display_matrix(int (*p)[3]){
        printf("Matrix:\n");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%d  ", p[i][j]);
            }
            printf("\n");
        }
}

void find_vac_pos(int (*p)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(p[i][j]==-1){
                pos[0] = i;
                pos[1] = j;
                return;
            }
        }
    }
}

void append_char(char *s, char t){
    int len = strlen(s);
    s[len] = t;
    s[len+1] = '\0';
}

void available_moves(int (*p)[3], char prev_move){
    find_vac_pos(p);
    char restricted;
    if(prev_move == 'R'){
        restricted = 'L';
    }    
    else if(prev_move == 'L'){
        restricted = 'R';
    }
    else if(prev_move == 'U'){
        restricted = 'D';
    }
    else if(prev_move == 'D'){
        restricted = 'U';
    }
    else if(prev_move == '\0'){
        restricted = '\0';
    }

    if(pos[0]!=0 && restricted!='U'){
        append_char(avail_moves, 'U');
    }    

    if(pos[0]!=2 && restricted!='D'){
        append_char(avail_moves, 'D');
    }

    if(pos[1]!=0 && restricted!='L'){
        append_char(avail_moves, 'L');
    }

    if(pos[1]!=2 && restricted!='R'){
        append_char(avail_moves, 'R');
    }
}

void copy_matrix(int (*s)[3], int (*d)[3]){
    // Copy matrix from source to destination
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            d[i][j] = s[i][j];
        }
    }
}

void flush_moves(){
    for(int i=0; i<5; i++){
        avail_moves[i] = '\0';
    }
}

void shuffle(char move, int (*succ)[3], int (*curr)[3]){
    copy_matrix(curr, succ);
    if(move == 'R'){
        succ[pos[0]][pos[1]] = succ[pos[0]][pos[1]+1];
        succ[pos[0]][pos[1]+1] = -1;
    }
    else if(move == 'L'){
        succ[pos[0]][pos[1]] = succ[pos[0]][pos[1]-1];
        succ[pos[0]][pos[1]-1] = -1; 
    }
    else if(move == 'U'){
        succ[pos[0]][pos[1]] = succ[pos[0]-1][pos[1]];
        succ[pos[0]-1][pos[1]] = -1;
    }
    else if(move == 'D'){
        succ[pos[0]][pos[1]] = succ[pos[0]+1][pos[1]];
        succ[pos[0]+1][pos[1]] = -1;
    }
}

void SHC(){
    int current[3][3], succ[3][3];
    copy_matrix(inp, current);
    int h_p = calc_heuristic(current);
    int f;
    char prev_move = '\0';
    do{
        flush_moves();
        f = 0;
        available_moves(current, prev_move);
        printf("\nAvailable moves:");
        puts(avail_moves);
        printf("\nHeuristic of current: %d", h_p);
        int i = 0;
        while(avail_moves[i]!='\0'){
            shuffle(avail_moves[i], succ, current);
            int h_s = calc_heuristic(succ);
            printf("\nHeuristic of successor on %c move: %d", avail_moves[i], h_s);
            if(h_s <= h_p){
                printf("\nNext state found on move %c ", avail_moves[i]);
                display_matrix(succ);
                f = 1;
                copy_matrix(succ, current);
                h_p = h_s;
                prev_move = avail_moves[i];
                break;
            }
            i++;
        }
    } 
    while(h_p!=0 && f==1);
    
    if(f==0){
        printf("\n\nNo more moves possible! SHL cannot find a solution!");
    }
    else{
        printf("\n\nGoal state reached!");
    }
}

void STHC(){
    int current[3][3], succ[3][3];
    copy_matrix(inp, current);
    int h_p = calc_heuristic(current);
    int f;
    char prev_move = '\0';
    char selected_move = '\0';
    do{
        flush_moves();
        f = 0;
        available_moves(current, prev_move);
        printf("\nAvailable moves:");
        puts(avail_moves);
        printf("\nHeuristic of current: %d", h_p);
        int i = 0;
        int min_h=10; char min_move='\0';
        while(avail_moves[i]!='\0'){
            shuffle(avail_moves[i], succ, current);
            int h_s = calc_heuristic(succ);
            printf("\nHeuristic of successor on %c move: %d", avail_moves[i], h_s);
            if(h_s<min_h){
                min_h = h_s;
                min_move = avail_moves[i];
            }
            i++;
        } 
        if(min_h<=h_p){
            f=1; 
            printf("\nNext state found on move %c ", min_move);
            shuffle(min_move, succ, current);
            display_matrix(succ);
            copy_matrix(succ, current); //Change parent
            h_p = min_h;    //Change parent's heuristic
        }
        //getchar();
    } 
    while(h_p!=0 && f==1);
    
    if(f==0){
        printf("\n\nNo more moves possible! STHC cannot find a solution!");
    }
    else{
        printf("\n\nGoal state reached!");
    }
}

int main(){
    //input();
    printf("Start ");
    display_matrix(inp);
    printf("Goal ");
    display_matrix(goal);
    printf("\n----------");
    printf("\nSHC Algorithm\n");
    SHC();
    printf("\n----------");
    printf("\nSTHC Algorithm\n");
    STHC();
}
