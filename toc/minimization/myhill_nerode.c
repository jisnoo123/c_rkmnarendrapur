#include <stdio.h>
#define MAX 100

int q[MAX], qnf[MAX], qf[MAX], q_initial; 
/*
    q[]: Set of states
    qf[]: Set of final states
    qnf[]: Set of non final states
    q_initial: inital state
*/

int n, ni, nf, nnf;
/*
    n: No. of states
    nf: No. of final states
    ni: No. of symbols in the input alphabet
    nnf: No. of non final states
*/

int inp[MAX]; // Input Alphabet

int trans_table[MAX][MAX]; // State transition table
int table[MAX][MAX]; //Myhill table

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

    // Initializing the non final states
    nnf = n - nf;
    int k = 0;

    for(int i=0; i<n; i++){
        int fl = 0;
        for(int j=0; j<nf; j++){
            if(i==qf[j]){
                fl++;
                break;
            }
        }
        if(fl==0){
            qnf[k] = i;
            k++;
        }
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
            printf("\nDelta(q%d, %d) = ",q[i],inp[j]);
            scanf("%d", &trans_table[i][j]);
        }
    }
}

int search(int key, int *a, int n){
    //Search the key in the array pointed by a having size n
    //Returns 1 if found otherwise 0
    int flag = 0;

    for(int i=0; i<n; i++){
        if(a[i] == key){
            flag++;
            break;
        }
    }

    return flag; 
}

void init_table(){
    // Initialize the myhill table with the following symbols representing:
    // -1: not required field of the table
    //  0: unmarked
    //  1: marked


    // Unmark the required fields, rest non required fields -1
    for(int i=0; i<n-1; i++){
        int k = i+1, c=0;
        for(int j=0; j<n-1; j++){
            if(c<k){
                table[i][j] = 0;
                c++;
            }
            else{
                table[i][j] = -1;
            }
        }
    }

    // Mark the state pairs such that one is final and the other is non final
    for(int i=0; i<n-1; i++){
        int k = i+1, c=0;
        for(int j=0; j<n-1; j++){
            if(c<k){
                // Required state pairs

                if((search(i+1, qf, nf)==1 && search(j, qnf, nnf)==1) || (search(i+1, qnf, nnf)==1 && search(j, qf, nf)==1)){
                    // One state is final the other is non final, so mark it
                    table[i][j] = 1;
                }
                
                c++;
            }
        }
    }
}

void display_myhill_table(){
    printf("\n");
    for(int i=0; i<n-1; i++){
        printf("q%d  ", i+1);
        int k = i+1, c=0;
        for(int j=0; j<n-1; j++){
            if(c<k){
                // Required state pairs
                printf("%d  ", table[i][j]);
                c++;
            }
        }
        printf("\n");
    }
    
    printf("   ");
    for(int j=0; j<n-1; j++){
        printf("q%d ", j);
    }
}

void display_transition_table(){
    // Display the transition table

    printf("\nThe state transition table is:\n");

    printf("         ");
    for(int j=0; j<ni; j++){
        printf("%d  ", inp[j]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        int temp = 0;

        if(q_initial == i && qf[i] == i){
            printf("-->(q%d)  ", i);
            temp++;
        }
        else if(q_initial == i){
            printf("  -->q%d  ", i);
            temp++;
        }

        int fn=0;
        for(int k=0; k<nf; k++){
            if(qf[k]==i){
                fn++;
                printf("   (q%d)  ", i);
                break;
            }
        }

        if(fn==0 && temp==0){
            printf("    q%d   ",i);
        }

        for(int j=0; j<ni; j++){
            printf("%d  ", trans_table[i][j]);
        }
        printf("\n");
    }
}

void compute(){
    // Mark those pairs whose transition state pairs are marked
    printf("Myhill Table Itn 0:");
    display_myhill_table();

    int stop = 1;
    int itn = 1;

    while(stop){
        int number_of_markings = 0;

        for(int i=0; i<n-1; i++){
            int k = i+1, c=0;
            for(int j=0; j<n-1; j++){
                if(c<k && table[i][j]==0){
                    // Required state pairs

                    for(int ia=0; ia<ni; ia++){
                        int q1, q2;
                        q1 = trans_table[i+1][inp[ia]];
                        q2 = trans_table[j][inp[ia]];
                        
                        if(i==2 && j==1){
                            printf("\ni = %d, j = %d", i, j);
                            printf("\ntable[%d][%d]= %d",q1+1, q2, table[q1+1][q2]);
                            printf("\ntable[%d][%d]= %d", q2+1, q1, table[q2+1][q1]);
                        }

                        if(table[q1-1][q2]==1 || table[q2-1][q1]==1){
                            //Mark
                            table[i][j] = 1;
                            number_of_markings++;
                            break;
                        }
                    }
                    
                    c++;
                }
            }
        }

        if(number_of_markings == 0){
            stop=0;
        }

        printf("\n Myhill Table after itn %d", itn);
        itn++;
        display_myhill_table();
    }

}

int main(){
    input();
    display_transition_table();
    init_table();
    compute();
}