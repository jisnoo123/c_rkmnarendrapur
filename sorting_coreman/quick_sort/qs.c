#include <stdio.h>
#define MAX 100

int a[MAX], n;

void input(){
	printf("Enter number of elements:");
	scanf("%d", &n);

	printf("\nEnter elements one by one:");
	for(int i=0; i<n; i++){
		printf("\nEnter element:");
		scanf("%d", &a[i]);
	}	
}

int partition(int* a, int p, int r){
	int x = a[r];
	int i = p-1, j = p;

	while(j<r){
		if(a[j]<x){
			int t = a[++i];
			a[i] = a[j];
			a[j] = t;
		}
		j++;
	} 
	int t = x;
	a[r] = a[i+1];
	a[i+1] = t;
	return i+1;
}

void quick_sort(int *a, int p, int r){
	if(p<r){
		int q = partition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

void display(){
	printf("\nArray:\n");
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

int main(){
	input();
	display();
	quick_sort(a, 0, n-1);
	display();
}
