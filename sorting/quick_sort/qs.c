#include <stdio.h>
#define MAX 100

int a[MAX], n;

void insert(){
    printf("Enter number of elements to sort:");
    scanf("%d", &n);

    printf("\nEnter elements one by one:\n");
    for (int i=0; i<n; i++)
    {
        printf("Enter element:");
        scanf("%d", &a[i]);
        printf("\n");
    }
}

void max_place(){
    //Find the max element and place it in nth index

    int max = a[0];
    
    for(int i=1; i<n; i++){
        if(a[i]>max)
            max = a[i];
    }

    //Place max in the last index
    a[n] = max;
}

void quick_sort(int m, int n){
    /* Sort array a[m .. n] using quick sort. We assume that a[n] contains max element*/
    
    if(m<n){
        //Contains more than one element
        int pivot = a[m]; // Choose the first element as the pivot
        int i = m;
        int j = n;

        do{
            do{
                i = i + 1;
            }
            while(a[i]<pivot);

            do{
                j = j - 1;
            }
            while(a[j]>pivot);

            if(i<j){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        while(i<j);
        
        int t = a[j];
        a[j] = a[m];
        a[m] = t;

        quick_sort(m,j);
        quick_sort(j+1,n);
    }
}

void display(){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    insert();
    max_place();

    printf("Original elements:\n");
    display();

    //Sort using quick sort
    quick_sort(0,n);


    printf("\nSorted elements:\n");
    display();
}