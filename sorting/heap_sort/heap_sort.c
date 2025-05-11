#include <stdio.h>
#define MAX 100

int heap[MAX], n;

void input(){
    printf("Enter the number of elements to sort:");
    scanf("%d",&n);
    printf("\n");
    heap[0] = 0; // We are ignoring the 0th index, because we cannot determine its left child by 2*i
    for(int i=1; i<=n; i++){
        printf("Enter element:");
        scanf("%d",&heap[i]);
    }
}

void heapify(int i, int n){
    /*Create max heap w.r.t node i. The left and right subtrees of node i are already max heaps*/
    //Here m is the last node's index
    int k = heap[i];
    int j = 2*i; //j points to the left child of node i

    while(j<=n){
        
        //Select the higher value of child and point j to that child
        if(j<n){
            //Right child exists
            if(heap[j]<heap[j+1]){
                j = j+1;
            }
        }

        if(k>heap[j]){
            heap[j/2] = k; //Put k in the parent if already children are lesser than k
            return;
        }
        else{
            heap[j/2] = heap[j]; //Put the higher child in the parent, but remember k is not inserted in the place of j.
            j = 2*j; // Point j to the next children, to continue satisfying heap property
        }
    }

    heap[j/2] = k; //In case j exceeds n, then k needs to put at the j/2 position
}

void swap(int i, int j){
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void heap_sort(){
    //Create the max heap first

    for(int i=n/2; i>=1; i--){
        heapify(i,n);
    }

    //Now the sorting part

    for(int i=n; i>=2; i--){
        swap(1,i);
        heapify(1,i-1);
    }
}

void display(){
    for(int i=1; i<=n; i++){
        printf("%d ", heap[i]);
    }
}

int main(){
    input();
    printf("Original elements are:\n");
    display();

    //Sort
    heap_sort();

    //Display sorted elements
    printf("\nSorted elements are:\n");
    display();
    printf("\n");
}