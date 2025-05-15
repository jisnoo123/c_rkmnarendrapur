//Non recursive merge sort
#define MAX 100
#include <stdio.h>

int start[MAX], stop[MAX], beg[MAX], mid[MAX], end[MAX];
int a[MAX],b[MAX],n;
int st[2], bme[3];
int top1=-1, top2=-1;

void push1(int item1, int item2){
    //Push item1 into start and item2 into stop
    top1++;
    start[top1] = item1;
    stop[top1] = item2; 
    
}

int *pop1(){
    //Pop item from start and stop
    if(top1==-1){
        printf("\nunderflow top1");
    }
    else{
        st[0] = start[top1];
        st[1] = stop[top1];
        top1--;
        return st;
    }
}

void push2(int item1, int item2, int item3){
    //Push item1 into begin, item2 into mid, item3 into end
    top2++;
    beg[top2] = item1;
    mid[top2] = item2; 
    end[top2] = item3;
    
}

int *pop2(){
    //Pop item from start and stop
    if(top2==-1){
        printf("\nunderflow top2");
    }
    else{
        bme[0] = beg[top2];
        bme[1] = mid[top2];
        bme[2] = end[top2];
        top2--;
        return bme;
    }
}

void input(){
    printf("Enter number of elements to sort:");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
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

void merge_sort(){
    //Non recursive merge sort

    //First push 0 into start and n-1 into stop
    push1(0,n-1);

    //Divide
    while(top1!=-1){
        int *st_pt = pop1();
        int bg = st_pt[0];
        int e = st_pt[1];
        //printf("\nbg=%d e=%d", bg, e);
        int m = (bg+e)/2;

        push2(bg,m,e); //Push b into beg[], m into mid[] and e into end[]
        
        if(bg<m){
            push1(bg,m);
        }
        
        if(m+1<e){
            push1(m+1,e);
        }
    }

    //Merging

    while(top2!=-1){
        int *bme_pt = pop2();
        int m = bme[0];
        int p = bme[1];
        int n = bme[2];

        //printf("\nm=%d p=%d n=%d",m,p,n);
        merging(m,p,n);
    }
}

void display(){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    input();
    printf("\nOriginal elements are:");
    display();

    //Sort
    merge_sort();

    printf("\nSorted elements are:");
    display();
    printf("\n");
}