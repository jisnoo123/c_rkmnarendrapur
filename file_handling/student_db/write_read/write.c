#include <stdio.h>
int main(){
    struct student{
        int roll;
        char name[100];
        float marks;
    } s;
    FILE *fp;
    fp=fopen("stuudentdb_write","wb");
    int i,n;
    printf("\nEnter number of records:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        setbuf(stdin,NULL);
        printf("Enter name,marks and roll:");
        fgets(s.name,100,stdin);
        scanf("%f%d",&s.marks,&s.roll);
        fwrite(&s,sizeof(s),1,fp);
    }
    fclose(fp);
}