#include <stdio.h>
int main(){
    struct student{
        int roll;
        char name[100];
        float marks;
    } s;
    FILE *fp;
    fp=fopen("stuudentdb_write","rb");
    int i,n;
    printf("ROLL\tMARKS\tNAME\n");
    while(fread(&s,sizeof(s),1,fp)>0){
        printf("%d\t%f\t%s\n",s.roll,s.marks,s.name);
    }
    fclose(fp);
}