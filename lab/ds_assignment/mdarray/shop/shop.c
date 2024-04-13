//Monthly sales
#include <stdio.h>
#define MAX 100
char item[MAX];
float cost[MAX],ms=0;
int sold[MAX],n;

void entry(){
    printf("\nEnter number of items:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("\nEnter name of item:");
        scanf("%c",&item[i]);
        printf("\nEnter unit price of item:");
        scanf("%f",&cost[i]);
        printf("\nEnter number of items sold:");
        scanf("%d",&sold[i]);
        printf("\nMonthly income from %c :Rs.%f",item[i],(sold[i]*cost[i]));
        printf("\n---------------");
    }
}

void compute(){
    //To compute monthly sales
    for(int i=0;i<n;i++){
        ms+=(sold[i])*(cost[i]);
    }
    printf("\nTotal monthly sales: Rs.%f",ms);
}

int main(){
    entry();
    compute();
}