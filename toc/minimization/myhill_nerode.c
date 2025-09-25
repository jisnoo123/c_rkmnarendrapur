#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX], qnf[MAX], qf[MAX], q_initial; 
/*
    q[]: Set of states
    qf[]: Set of final states
    qnf[]: Set of non final states
    q_initial: inital state
*/

int n, ni, nf, nnf, nusp;
/*
    n: No. of states
    nf: No. of final states
    ni: No. of symbols in the input alphabet
    nnf: No. of non final states
    nusp: No. of unmarked state pairs
*/

int inp[MAX]; // Input Alphabet

int trans_table[MAX][MAX]; // State transition table
int table[MAX][MAX]; //Myhill table

int indiv[MAX], non_indiv[MAX]; // indiv contains those states which are individual, i.e do not have equivalent states

int n_non_indiv = 0; // No. of non individuals

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

int check_final(int q){
    // Check if a state is a final state or not
    int i=0, flag = 0;

    while(qf[i]!=-1){
        if(qf[i]==i){
            flag++;
            break;
        }
        i++;
    }

    return flag;
}

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

    // Initial initialisation of array of final states with -1
    for(int i=0; i<MAX; i++){
        qf[i] = -1;
    }

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

    //Initialize the array of pointers
    for(int i=0; i<MAX; i++){
        heads[i] = (struct node *)(-1);
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
    printf("\n\n");
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

    printf("\n\n");
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

        if(q_initial == i && check_final(i)==1){
            temp++;
            printf("-->(q%d)  ", i);
        }
        else if(q_initial == i){
            temp++;
            printf("  -->q%d  ", i);
        }

        int fn=0;

        if(temp==0){
            for(int k=0; k<nf; k++){
                if(qf[k]==i){
                    fn++;
                    printf("   (q%d)  ", i);
                    break;
                }
            }
        }
        
        if(fn==0 && temp==0){
            printf("    q%d   ",i);
        }

        for(int j=0; j<ni; j++){
            printf("%d  ", table[i][j]);
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

        printf("\nMyhill Table after itn %d", itn);
        itn++;
        display_myhill_table();
    }
}

int common_element(struct node *a, struct node *b){
    // Returns 1 if there is any common element between the linked lists pointed by a and b
    struct node *p = a;
    struct node *q = b;
    int flag = 0;

    while(p!=NULL){
        while(q!=NULL){
            if(p->data == q->data){
                flag++;
                break;
            }
            q = q->link;
        }
        p = p->link;
    }

    return flag;
}

void merge(struct node *p, struct node *q, int j){
    // Merge the linked lists pointed by p and q.The final linked list will be pointed by p and the head address q would be removed from the array of pointers
    while(p->link!=NULL){
        p = p->link;
    }

    p->link = q;

    heads[j] = (struct node *)(-2); //-2 indicates that a previously existing head has been removed.
}

void remove_common_elements(struct node *head){
    // Remove common elements from a linked list
    struct node *p = head;

    while(p!=NULL){
        struct node *q = p->link;
        struct node *prev = p;
        while(q!=NULL){
            if(p->data == q->data){
                //Remove q
                prev->link = q->link;
                free(q);
            }
            q = q->link;
        }
        p = p->link;
    }
}

void traverse(struct node *head){
    // Traverse the linked list pointed by head
    struct node *p = head;

    printf("( ");
    while(p!=NULL){
        printf("%d ", p->data);
        non_indiv[n_non_indiv] = p->data;
        n_non_indiv++;
        p = p->link;
    }
    printf(")\n");
}

void minimize(){
    // Find the equivalent states
    int head_index = 0;
    nusp = 0;

    // Create linked list of state pairs which are unmarked
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(table[i][j]==0){
                nusp++;
                int q1 = i+1;
                int q2 = j;
                heads[head_index] = create_node(q1);
                heads[head_index]->link = create_node(q2);
                head_index++;
            }
        }
    }

    // Find if any state pairs exist with common elements
    for(int i=0; i<nusp; i++){
        for(int j=i+1; j<nusp; j++){
            if(common_element(heads[i], heads[j])){
                merge(heads[i], heads[j], j);
            }
        }
    }

    // Remove common elements from the merged linked lists, make it clean
    head_index = 0;
    while(heads[head_index]!=-1){
        if(heads[head_index]!=-2){
            struct node *head = heads[head_index];
            remove_common_elements(head);
        }
        head_index++;
    }
}

void display_result(){
    int head_index = 0;

    printf("The final equivalence classes are:\n");
    // Display the non individuals
    while(heads[head_index]!=-1){
        if(heads[head_index]!=-2){
            traverse(heads[head_index]);
        }
        head_index++;
    }

    // Display the individuals
    for(int i=0; i<n; i++){
        int flag = 0;
        for(int j=0; j<n_non_indiv; j++){
            if(q[i] == non_indiv[j]){
                flag++;
                break;
            }
        }
        if(flag == 0){
            printf("(%d)\n", i);
        }
    }
}

int main(){
    input();
    display_transition_table();
    init_table();
    compute();
    minimize();
    display_result();
}