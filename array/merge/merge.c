#include <stdio.h>
int main(){
    int a[100],b[100],c[100],m,n,min,i,j,k;
    printf("Enter size of first array and second array: ");
    scanf("%d%d",&m,&n);
    //input first array
    printf("\n Enter elements of first array");
    for(i=0;i<m;i++){
        printf("\nEnter element: ");
        scanf("%d",&a[i]);
    }
    //input second array
    printf("\n Enter elements of second array");
    for(i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&b[i]);
    }
    //storing minimum size of the two arrays in min
    if(m>n)
        min=n;
    else
        min=m;
    //merging two arrays
    i=0;j=0;k=0;
    while(i<m && j<n){
        if(a[i]>b[j]){
            c[k]=b[j];
            j++;
        }
        else{
            c[k]=a[i];
            i++;
        }
        k++;
    }
    while(i<n){
        c[k]=a[i];
        i++;k++;
    }
    while (j<m){
        c[k]=b[j];
        j++;k++;
    }
    printf("\n Merged array: \n");
    //displaying merged array
    for(i=0;i<(m+n);i++){
        printf("%d ",c[i]);
    }
}