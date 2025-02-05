#include <stdio.h>
int main(){
    int empno,exp;
    float sal;
    char name[100];
    printf("Enter employee number and experience:");
    scanf("%d%d",&empno,&exp);
    setbuf(stdin,NULL);
    printf("\nEnter salary:");
    scanf("%f",&sal);
    printf("\nEnter name:");
    setbuf(stdin,NULL);
    gets(name);
    //Displaying in a database format
    printf("Name\tEmpNo\tExp(yrs)\tSalary($)\n");    
    printf("\n%s\t%d\t%d\t\t%g",name,empno,exp,sal);  
}