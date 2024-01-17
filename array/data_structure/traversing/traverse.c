#include <stdio.h>
void traverse(int *a, int l, int u){
    //Here l and u are the two indices of taversing
    int i=l;
    while(i<=u){
        printf("%d\n",a[i]);
    }
    printf("Traversing completed");
}