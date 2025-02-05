//Program to seperate positive and negative numbers and then increment and decrement them by 1 respectively
#include <stdio.h>
int check(int arg){
    //Returns 0 if number is -ve and 1 if +ve
    if(arg<0){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int a[10],n[10],p[10],nc=0,pc=0,i;
    //Input
    printf("Enter 10 elements into the array: ");
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    //seperation
    for(i=0;i<10;i++){
        if(check(a[i])==0){
            n[nc]=a[i];
            nc++;
        }
        else{
            p[pc]=a[i];
            pc++;
        }
    }
    //Display negative and positive numbers
    puts("negative numbers:");
    for(i=0;i<nc;i++){
        printf("%d ",n[i]);
    }
    puts("Positive numbers:");
    for(i=0;i<pc;i++){
        printf("%d ",p[i]);
    }
    //operation
    puts("negative numbers after decrement:");
    for(i=0;i<nc;i++){
        n[i]--;
        printf("%d ",n[i]);
    }
    puts("positive numbers after increment:");
    for(i=0;i<pc;i++){
        p[i]++;
        printf("%d ",p[i]);
    }
}