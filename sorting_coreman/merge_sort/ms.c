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

void merging(int* a, int p, int q, int r){
	// Merging sorted a[p..q] and a[q+1..r] into a single sorted array
	
	int n_l = q-p+1; // No. of elements in the left
	int n_r = r-q;	// No. of elements in the right
	int L[n_l + 1], R[n_r + 1];	// Two arrays L[] (for left) and R[] (for right) with an extra element to hold infinity at the 						end
	
	// Copy a[p..q] to L[]
	for(int i=0; i<n_l; i++){
		L[i] = a[p+i];
	}

	// Copy a[q+1..r] to R[]
	for(int i=0; i<n_r; i++){
		R[i] = a[q+1+i];
	}

	// Put infinity at the end of L[] and R[]
	L[n_l] = 65432;
	R[n_r] = 65432;

	// Merge
	int i=0, j=0;
	for(int k=p; k<=r; k++){
		if(L[i]<R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}

}

void merge_sort(int *a, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(a, p, q);
	      	merge_sort(a, q+1, r);
		merging(a, p, q, r);	
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
	merge_sort(a, 0, n-1);
	display();
}
