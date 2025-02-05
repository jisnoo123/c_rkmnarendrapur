#include <stdio.h>
//Ascending order
int main(){
    int n, arr[100],i,pass,t,j,k;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("\n");
    //Displaying original array
    printf("Original array: \n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(pass = 1;pass<=n-1;pass++){
        for(j=0;j<n-pass;j++){
            if(arr[j+1]<arr[j]){
                t = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= t;
            }
        }
        printf("\n Pass : %d \n ",pass);
        for(k=0;k<n;k++){
        	printf("%d ",arr[k]);
		}
    }
    printf("\n\n Sorted array: \n");
    //Displaying new array
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
