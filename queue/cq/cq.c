//Circular queue using array
#include <stdio.h>
#define MAX 100
int cq[MAX],f=-1,r=-1,n;

void display(){
    if(f==-1&&r==-1){
        printf("\n--Empty Queue--");
    }
    else{
        printf("\nQueue is:");
        int i=f;
        while(i!=r){
            printf("%d ",cq[i]);
            i=(i+1)%n;
        }
        printf("%d",cq[i]);
    }
}

void enqueue(){
    int data;
    if(f==-1&&r==-1){
        f=0;
        r=0;
        printf("\nEnter data to enqueue:");
        scanf("%d",&data);
        cq[r]=data;
    }
    else{
        if((r+1)%n==f){
            printf("\n--Queue is full--");
        }
        else{
            r=(r+1)%n;
            printf("\nEnter data to enqueue:");
            scanf("%d",&data);
            cq[r]=data;
        }
    }
}

int dequeue(){
    if(f==-1&&r==-1){
        printf("\n--Queue empty--");
        return -404;
    }
    else{
        int item=cq[f];
        if(f==r){
            //Make queue empty
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%n;
        }
        return item;
    }
}

int main(){
    int ch,c=0,item;
    do{
        printf("\nEnter 1 to enqueue,2 to dequeue,3 to display and 4 to stop:");
        scanf("%d",&ch);
        switch(ch){
            case  1:
                if(c==0){
                    c++;
                    printf("\nEnter size of array:");
                    scanf("%d",&n);
                }
                enqueue();
                break;

            case 2:
               item=dequeue();
               if(item!=-404){
                    printf("\nDeqeued item is: %d",item);
               }
               break;

            case 3:
                display();
                break;

            case 4:
                break; 
        }
    }
    while(ch!=4);
}