#include <stdio.h>
int main(){
    FILE *fp;
    char line[100];
    fp=fopen("poem.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%s",line);
        printf("\n%s",line);
    }
    fclose(fp);
}