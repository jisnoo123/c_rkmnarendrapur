#include<stdio.h>
int main(){
    FILE *fp;
    char ch;
    fp=fopen("num.txt","r");
    while(!feof(fp)){
        ch=fgetc(fp);
        printf("%c",ch);
    }
    fclose(fp);
}