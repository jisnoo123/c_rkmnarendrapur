#include <stdio.h>
#define MAX 100

int a[MAX], n;

void display(int* a, int n){
    printf("\nArray:");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

void input(){
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter array elements:");
    for(int i=0; i<n; i++){
        printf("\nEnter element: ");
        scanf("%d", &a[i]);
    }
}

void insertion_sort(){
    for(int j=1; j<n; j++){
        int key = a[j];
        int i = j-1;

        while(i>-1 && a[i]>key){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
}

int main(){
    input();
    display(a, n);
    insertion_sort();
    display(a, n);
}