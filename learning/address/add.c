#include <stdio.h>
int main(){
    int b[2]={0,1};
    int *a=&b[0];
    //printf("%d",sizeof(int));
    //642292
    printf("address %u",a);
    printf("\nelements %d %d",*a,*(a+1));
}