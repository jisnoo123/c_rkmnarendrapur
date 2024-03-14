#include <stdio.h>
#define MAX 100
int q[MAX];
int front=-1,rear=-1,n;

void enqueue(){
    /*
    Insertion will take place from rear and deletion from front
    When inserting, increment the rear and front. So rear and front will both point 
    to the top of the queue, i.e, the current most element.
    */

    if(rear==n-1){
        printf("\n--Overflow--");
    }
    else{
        int data;
        printf("\nEnter your data:");
        scanf("%d",&data);
        q[++rear]=data;
        front++;
    }
}

void dequeue(){
    /* 
    Deletion will take place from the front and we will decrement 
    both the front and rear so that both points to the current most 
    element.
    */

    if(front==-1){
        printf("\n--Underflow--");
    }
    else{
        printf("\nelement dequeued is: %d",q[front--]);
        rear--;
    }
}

void traverse(){
    int i=front;
    if(rear!=-1){
        printf("\nElements are:");
        while(i!=-1){
            printf("\n%d",q[i]);
            i--;
        }
    }
    else{
        printf("\nStack empty");
    }
}

int main(){
    printf("\nEnter max number of elements in queue:");
    scanf("%d",&n);
    int inp;
    do{
        printf("\nEnter 1 to push,2 to pop,3 to traverse and 4 to quit:");
        scanf("%d",&inp);
        switch(inp){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                break;
        }
    }
    while(inp!=4);
}