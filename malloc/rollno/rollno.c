#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p,n,i,*q;
    printf("Enter number of students:");
    scanf("%d",&n);
    p=(int*)(malloc(n*sizeof(int)));
    q=p;
    printf("\nEnter roll numbers one by one");
    for(i=0;i<n;i++){
        printf("\nEnter roll number:");
        scanf("%d",p);
        p++;
    }
    printf("\nRoll numbers:");
    for(i=0;i<n;i++){
        printf("\n%d",(*q));
        q++;
    }
}