#include <stdio.h>
#include <string.h>
#define MAX 100
int r[MAX],N;
char n[MAX][MAX],b[MAX][MAX];
float c[MAX];

void display(){
    for(int i=0;i<N;i++){
        printf("\nName of student:%s\nRegn No:%d\nBranch:%s\nCGPA:%f\n\n",&n[i],r[i],&b[i],c[i]);
    }
}
void entry(){
    //Take data elements
    printf("\nEnter no. of numbers to input:");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        fflush(stdin);
        printf("\nEnter name:");
        scanf("%s",&n[i]);

        fflush(stdin);
        printf("\nEnter Regn No:");
        scanf("%d",&r[i]);

        printf("\nEnter Branch:");
        scanf("%s",&b[i]);

        printf("\nEnter CGPA:");
        scanf("%f",&c[i]);

        fflush(stdin);
    }
}

void ls_reg(){
    int reg;
    printf("\n--Enter Regn no. to search:");
    scanf("%d",&reg);
    for(int i=0;i<N;i++){
        if(r[i]==reg){
            printf("\nName of student:%s\nBranch:%s\nCGPA:%f",n[i],b[i],c[i]);
            return;
        }
    }
    printf("\n--Student not found--");
}

void bs_reg(){
    //Bubble sort the regn no.s
    for(int i=1;i<N;i++){
        for(int j=0;j<N-i;j++){
            if(r[j]>r[j+1]){
                //Swap regn no.s
                int t=r[j+1];
                r[j+1]=r[j];
                r[j]=t;

                //Swap name
                char t1[MAX];
                strcpy(t1,n[j+1]);
                strcpy(n[j+1],n[j]);
                strcpy(n[j],t1);

                //Swap branch
                strcpy(t1,b[j+1]);
                strcpy(b[j+1],b[j]);
                strcpy(b[j],t1);

                //Swap cgpa
                float cg;
                cg=c[j+1];
                c[j+1]=c[j];
                c[j]=cg;
            }
        }
    }
}

void bin_reg(){
    bs_reg();
    int k,lb,ub,mid;
    printf("Enter regn no. to search: ");
    scanf("%d",&k);
    printf("\n");
    lb=0;ub=N-1;
    mid=(lb+ub)/2;
    while(lb<=ub){
        if(r[mid]==k){
            printf("\nName of student:%s\nBranch:%s\nCGPA:%f",n[mid],b[mid],c[mid]);
            break;
        }
        else if (r[mid]<k){
            lb=mid+1;
            mid=(lb+ub)/2;
        }
        else if(r[mid]>k){
            ub=mid-1;
            mid=(lb+ub)/2;
        }
    }
    if(lb>ub)
        printf("\n--Student not found--");
}

int main(){
    int ch;
    entry();
    do{
        printf("\nEnter 1 to linear search a regn no, 2 to bubble sort, 3 to binary search and 4 to stop:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                ls_reg();
                break;
            case 2:
                bs_reg();
                display();
                break;
            case 3:
                bin_reg();
                break;
            case 4:
                break;
        }
    }
    while(ch!=4);
}