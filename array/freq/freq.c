#include <stdio.h>
int main(){
    int a[100],b[100],c,n,i,j,f,m,t,flag;
    printf("Enter size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    //calculating frequency
    b[0]=a[0];c=0;
    for(i=0;i<n;){
        f=0;m=a[i];
        if(c==0){
            b[c]=m;
            c++;
            for(j=0;j<n;j++){
                if(m==a[j])
                    f++;
            }
            printf("\nFrequency of %d is %d ",m,f);
        }
        else{
            flag=0;
            for(int j=0;j<c;j++){
                if(m==b[j])
                    flag++;
            }
            if(flag!=0){
                i++;
                continue;
            }
            else{
                b[c]=m;
                c++;
                for(j=0;j<n;j++){
                    if(m==a[j])
                        f++;
                }
                printf("\nFrequency of %d is %d ",m,f);
            }
        }
    }
}