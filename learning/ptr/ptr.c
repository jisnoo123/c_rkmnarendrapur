#include <stdio.h>
int main(){
    char *c;
    int b[2]={3,4};
    int *i;
    c=&b[0];
    i=&b[0];
    printf("\nsize of char is %d",sizeof(char));
    printf("\nsize of int is %d",sizeof(int));
    printf("\nConsecutive address of b[] by character pointer is %u %u",c,c+1);
    printf("\nConsecutive address of b[] by integer pointer is %u %u",i,i+1);
    printf("\nelement pointed by character pointer is %d %d %d %d %d %d %d %d",*c,*(c+1),*(c+2),*(c+3),*(c+4),*(c+5),*(c+6),*(c+7));
    printf("\nelement pointed by integer pointer is %d %d",*i,*(i+1));
}
/*
ptr.c: In function 'main':
ptr.c:6:6: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
     c=&b[0];
      ^
PS C:\Users\Hewlett Packard\Desktop\GIT\c_rkmnarendrapur\learning\ptr> ./a.exe

size of char is 1
size of int is 4
Consecutive address of b[] by character pointer is 6422272 6422273
Consecutive address of b[] by integer pointer is 6422272 6422276
element pointed by character pointer is 3 0 0 0 4 0 0 0
element pointed by integer pointer is 3 4
*/