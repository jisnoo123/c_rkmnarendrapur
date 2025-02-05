//Queue using circular array representation

/*Condition of overflow: (rear+1)mod n ==front
  Condition of underflow: rear==front
*/
#include <stdio.h>
#define n 100

int queue[n];
int rear=0,front=0;

void enqueue(int item){
    rear=(rear+1)%n;
    if(rear==front){
        printf("Overflow");

        //Repositioning rear one index backward
        if(rear==0)
            rear=n-1;
        else
            rear=rear-1;
    }
    else{
        queue[rear]=item;
    }
}

int dequeue(){
    if(front==rear){
        printf("Underflow");
        return -1;
    }
    else{
        front=(front+1)%n;
        int t=queue[front];
        return t;
    }
}

int main(){
    int inp;
    do{
        printf("Enter 1 to enqueue and 2 to dequeue and 3 to stop");
        scanf("%d",&inp);
        if(inp==1){
            printf("\nEnter element: ");
            int temp;
            scanf("%d",&temp);
            enqueue(temp);
        }
        else if(inp==2){
            int t2=dequeue();
            printf("\n%d",t2);
        }
    }
    while(inp!=3);
}