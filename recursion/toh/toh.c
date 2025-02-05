/*Towers of Hanoi
Rules: There are three towers A B C . A has n number of stones , from samller to larger.
You need to transfer all the stones to C , having the same order as C.
Remember that you cannot put a larger stone over a smaller one.
*/
#include <stdio.h>
void toh(int n,char A,char B, char C){
    //n is the number of stones , A,B and C are the names of the towers
    if(n>1){
        toh(n-1,A,C,B);
        printf("\n%c --> %c",A,C);
        toh(n-1,B,A,C);
    }
    else if (n==1){
        printf("\n%c --> %c",A,C);
    }
}
int main(){
    char x,y,z;
    int n;
    printf("Enter number of stones:");
    scanf("%d",&n);
    printf("\nEnter the names of towers:");
    scanf("%c%c%c",&x,&y,&z);
    toh(n,x,y,z);
}