#include <stdio.h>
int main(){
    char *c;
    int b[2]={3,4};
    int *i;
    c=&b[0];
    i=&b[0];
    printf("size of char is %d",sizeof(char));
    printf("\naddress of b by character pointer is %u",c);
    printf("\naddress of b by integer pointer is %u",c+1);
    printf("\nelement pointed by character pointer is 1.%c 2.%c 3.%c 4.%c 5.%c 6.%c 7.%c 8.%c",*c,*(c+1),*(c+2),*(c+3),*(c+4),*(c+5),*(c+6),*(c+7));
    printf("\nelement pointed by character pointer is %d %d %d %d %d",*c,*(c+1),*(c+2),*(c+3),*(c+4));
    printf("\nelement pointed by integer pointer is %d %d",*i,*(i+1));
}