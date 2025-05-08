#include <stdio.h>
#define MAX 100

int a[MAX], n;

void insert(){
    //Take the elements input in an array starting from index 1 to n. Index 0 serves as a dummy place 
    printf("Enter number of elements to sort:");
    scanf("%d",&n);

    printf("\nEnter elements one by one:\n");
    for(int i=1; i<=n; i++){
        printf("Enter element:");
        scanf("%d", &a[i]);
        printf("\n");
    }
}

void insertion_sort(){
    //Index 1 needs not be sorted because one element is already sorted

    for(int i=2; i<=n; i++){
        int k = a[i];
        a[0] = k; //Keeping the selected element to be sorted in the 0th index
        int j = i-1;

        while(a[j]>k){
            a[j+1] = a[j];
            j = j-1;
        }
        //Found the proper place for inserting the selected element k
        a[j+1] = k; 
    }
}

void display(){
    for(int i=1; i<=n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    //Taking the elements input
    insert();
    printf("Your elements:\n");
    display();

    //Performing insertion sort
    insertion_sort();

    //Displaying final result
    printf("\nAfter sorting:\n");
    display();
    printf("\n");
}