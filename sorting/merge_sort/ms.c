#define MAX 100
#include <stdio.h>

int a[MAX], b[MAX], num;

void input(){
    printf("Enter number of elements:");
    scanf("%d", &num);

    for(int i=0; i<num; i++){
        printf("Enter element:");
        scanf("%d", &a[i]);
        printf("\n");
    }
}

void merging(int m, int p, int n){
    //Merge two sorted arrays a[m...p] and a[p+1 ... n] into a final sorted array b[m ... n]
    int i = m;
    int j = p+1;
    int k = m;

    while(i<=p && j<=n){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i<=p){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j<=n){
        b[k] = a[j];
        j++;
        k++;
    }

    //Copy the array b[] to a[]

    for(int i=m; i<=n; i++){
        a[i] = b[i];
    }
}

void merge_sort(int m, int n){
    if(m<n){
        //More than one element is present
        int p = (m+n)/2;
        merge_sort(m,p);
        merge_sort(p+1,n);
        merging(m, p, n);
    }
}

void display(){
    for(int i=0; i<num; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    input();

    printf("Elements are:\n");
    display();

    //Applying merge sort
    merge_sort(0,num-1);

    printf("Sorted elements:\n");
    display();
}