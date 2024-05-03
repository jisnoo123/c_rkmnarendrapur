#include <stdio.h>
#define MAX 100
int dq[MAX];
int r=-1,f=-1,n;

int overflow(){
    //Dequeue full
    if((f==0&&r==n-1)||(f==r+1)){
        return 1;
    }
    else{
        return 0;
    }
}

int underflow(){
    //Dequeue empty
    if(f==-1&&r==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int enqfront(int data){
    if(overflow()){
        printf("\n--Dequeue full--");
    }
    else{
        if(f==-1&&r==-1){
            f=0;
            r=0;
        }
        else if(f==0){
            f=n-1;
        }
        else{
            f--;
        }
        dq[f]=data;
    }
}

int deqfront(){
    int item;
    if(underflow()){
        printf("\n--Dequeue empty--");
    }
    else{
        item=dq[f];
        if(f==r){
            f=-1;
            r=-1;
        }
        else if(f==n-1){
            f=0;
        }
        else{
            f++;
        }
    } 
}

void enqrear(int data){
    if(overflow()){
        printf("\n--Overflow--");
    }
    else{
        if(r==-1&&f==-1){
            r=0;
            f=0;
        }
        else if(r==n-1){
            r=0;
        }
        else{
            r++;
        }
        dq[r]=data;
    }
}

int deqrear(){
    int item;
    if(underflow()){
        printf("\n--Dequeue empty--");
    }
    else{
        item=dq[r];
        if(r==0){
            r=n-1;
        }
        else if(r==f){
            r=0;
            f=0;
        }
        else{
            r--;
        }
        return item;
    }
}

void rdisplay(){
    int i=r;
    while(i!=f){
        printf("%d ",dq[i]);
        i=(i-1)%n;
    }
    printf("%d ",dq[i]);
}

void fdisplay(){
    int i=f;
    while(i!=r){
        printf("%d ",dq[i]);
        i=(i+1)%n;
    }
    printf("%d ",dq[i]);
}

int main(){
    int ch,data;
    do{
        printf("\nEnter 1 to enqueue through rear, 2 from front,3 to dequeue through rear and 4 through front, 5 to display through rear and 6 from front and 7 to exit:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter data to insert:");
                scanf("%d",&data);
                enqrear(data);
                break;
            case 2:
                printf("\nEnter data to insert:");
                scanf("%d",&data);
                enqfront(data);
                break;
            case 3:
                data=deqrear();
                printf("\nElement dequeued is : %d",data);
                break;
            case 4:
                data=deqfront();
                printf("\nElement dequeued is : %d",data);
                break;
            case 5:
                rdisplay();
                break;
            case 6:
                fdisplay();
                break;
            case 7: 
                break;
        }
    }
    while(ch!=7);
}