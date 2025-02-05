#include <stdio.h>
#define MAX 100
int q[MAX];
int f=-1,r=-1,c=0;
//c=0 means insertion for the first time and c=1 means insertion other than first time
void insert(int n){
    if(r==MAX-1){
        printf("Overflow");
    }
    else{
        if(c==0){
            f=r+1;
            c++;
        }
        q[++r]=n;
    }
}

void delete(){
    if(f==r+1){
        printf("Underflow");
        c=0;
    }
    else{
        printf("%d",q[f++]);
    }
}

void status(){
    int tot=r-f+1; //Total elements in queue
    printf("Total elements:%d",tot);
}

int main(){
    int ip;
    do{
        printf("\nEnter 1 to insert, 2 to delete,3 to status and 4 to stop: ");
        scanf("%d",&ip);
        if(ip==1){
            int data;
            printf("Enter data: ");
            scanf("%d",&data);
            insert(data);
        }
        else if(ip==2){
            delete();
        }
        else if(ip==3){
            status();
        }
        else{
            printf("\n--QUIT--");
            break;
        }
    }
    while(ip!=4);
}