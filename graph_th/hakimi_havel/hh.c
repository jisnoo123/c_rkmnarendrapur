#include <stdio.h>
#define NULL 0
#define MAX 100

int traverse(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int* d_sort(int *a,int n){
    int t;
    for(int pass = 1;pass<=n-1;pass++){
        for(int j=0;j<n-pass;j++){
            if(a[j+1]>a[j]){
                t = a[j];
                a[j]=a[j+1];
                a[j+1]= t;
            }
        }
    }
    return a;
}

int* opn(int *a,int n){
    int d;
    d=a[0];
    a[0]=0;
    for(int k=1;k<=d;k++){
        //Decrement the next d elements by 1
        a[k]--;
    }
    return a;
}

int check(int *a,int n){
    int c=0,neg=0;
    /*To check whether the array elements are all 0s 
      Return 1 if all are 0s, -1 if there is atleast one negative element
      else returns 0.
    */

    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg++;
            break;
        }
        else if(a[i]!=NULL){
            c++;
            break;
        }
    }
    if(neg!=0)
        return -1;
    else if(c!=0)
        return 0;
    else
        return 1;
}
int main(){
    int a[MAX],n;
    //Initializing the whole array with 0
    for(int i=0;i<MAX;i++){
        a[i]=NULL;
    }
    printf("Enter size of array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&a[i]);
    }
    printf("\n");
    puts("original vector:");
    traverse(a,n);
    printf("\n\n");
    //Executing the algorithm
    int f=0;
    while(check(a,n)!=1){
        d_sort(a,n);
        printf("\nAfter sorting:\n");
        traverse(a,n);
        opn(a,n);
        printf("\nAfter operation\n");
        traverse(a,n);
        if(check(a,n)==-1){
            f++;
            break;
        }
    }
    printf("\n\n--Conclusion--");
    if(f==0)
        printf("\nVector is graphic");
    else
        printf("\nVector is not graphic");
}