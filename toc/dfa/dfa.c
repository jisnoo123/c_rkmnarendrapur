// DFA: Deterministic Finite Automata
#include <stdio.h>
#define MAX 100

int q[MAX], q_initial, qf[MAX]; 
/*
    q[]: Set of states
    q_initial: inital state
    qf[]: Set of final states
*/

int n, nf, ni; 
/*
    n: No. of states
    nf: No. of final states
    ni: No. of symbols in the input alphabet
*/

int inp[MAX]; // Input Alphabet

int input_string[MAX]; // Input String
int len; //Length of input string

int sequence[MAX]; //Sequence of states traversed during the processing of the input string

int table[MAX][MAX]; // State transition table

void input(){
    // Taking the states
    printf("Enter the number of states in the DFA:");
    scanf("%d", &n);

    // Assuming the states to be named as q0, q1, q2, ....
    for(int i=0; i<n; i++){
        q[i] = i;
    }

    // Initial state
    printf("\nEnter the state which is the inital one:");
    scanf("%d", &q_initial);

    // Final states
    printf("\nEnter the number of final states:");
    scanf("%d", &nf);

    printf("\nEnter the state numbers which are final:");
    for(int i=0; i<nf; i++){
        scanf("%d", &qf[i]);
    }

    // Input alphabet
    printf("\nEnter the number of symbols in the input alphabet:");
    scanf("%d", &ni);
    for(int i=0; i<ni; i++){
        printf("\nEnter symbol:");
        scanf("%d", &inp[i]);
    }

    // State Transition Table
    printf("\nNow define the transition function:");
    for(int i=0; i<n; i++){
        for(int j=0; j<ni; j++){
            printf("\nDelta(%d, %d) = ",q[i],inp[j]);
            scanf("%d", &table[i][j]);
        }
    }

    //Input String
}

void display_transition_table(){
    // Display the transition table

    printf("\nThe state transitipn table is:\n");

    printf("    ");
    for(int j=0; j<ni; j++){
        printf("%d  ", inp[j]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("q%d  ", i);
        for(int j=0; j<ni; j++){
            printf("%d  ", table[i][j]);
        }
        printf("\n");
    }
}
void inp_string(){
    printf("\nEnter the length of input string:");
    scanf("%d", &len);
    printf("\nEnter the input string one by one:\n");
    for(int i=0; i<len; i++){
        scanf("%d", &input_string[i]);
    }
}

void acceptability(){
    // Check the acceptability of the string
    sequence[0] = q_initial;
    int q_current = q_initial;

    for(int i=0; i<len; i++){
        int symbol = input_string[i];
        int q_next = table[q_current][symbol];
        sequence[i+1] = q_next;
        q_current = q_next;
    }
}

int check(){
    // Returns 1 if string is accepted otherwise 0

    int fstate = sequence[len];
    int flag = 0;
    for(int i=0; i<nf; i++){
        if(fstate == qf[i]){
            flag = 1;
            break;
        }
    }

    return flag;
}

void result(){
    for(int i=0; i<len; i++){
        printf("%d", input_string[i]);
    }

    if(check() == 1){
        printf(" string is accepted");
    }
    else{
        printf(" string is not accepted");
    }

    printf("\nSequence of states:");

    for(int i=0; i<len+1; i++){
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int main(){
    input();
    display_transition_table();
    inp_string();
    acceptability();
    result();
}