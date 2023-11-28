#include <stdio.h>
#include <stdlib.h>
int main(int argc , char *argv[]){
    printf("%d",atoi("10"));
    int i,s=0,n;
    for(i=1;i<argc;i++){
        n=atoi(argv[i]);
        s=s+n;
    }
    printf("Sum is %d",s);
}