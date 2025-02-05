#include <stdio.h>
#define MAX 100
int score[3][4];
char name[3];

void entry(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        printf("\nEnter name of student:");
        scanf("%c",&name[i]);
        printf("\nEnter score in test:");
        scanf("%d",&score[i][0]);
        printf("\nEnter score in project:");
        scanf("%d",&score[i][1]);
        printf("\nEnter score in homework:");
        scanf("%d",&score[i][2]);
        printf("\nEnter score in quiz:");
        scanf("%d",&score[i][3]);
        printf("\n-------");
    }
}

void grade(){
    for(int i=0;i<3;i++){
        float g=0;
        g=g+(0.4*score[i][0])+(0.15*score[i][1])+(0.25*score[i][2])+(0.2*score[i][3]);
        printf("\nGrade of %c : %f",name[i],g);
    }
}

int main(){
    entry();
    grade();
}