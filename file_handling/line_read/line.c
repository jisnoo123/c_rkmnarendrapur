#include <stdio.h>
int main(){
    FILE *fp;
    char line[100];
    fp=fopen("poem.txt","r");
    while(fgets(line,100,fp)!=NULL)
        printf("%s",line);
    fclose(fp);
}