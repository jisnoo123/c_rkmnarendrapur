#include <stdio.h>
#define MAX 100
int s1[MAX],s2[MAX],t1=-1,t2=-1,n;

void push_s1(){
    int data;
    if(t1!=n-1){
        printf("\nEnter data to enqueue:");
        scanf("%d",&data);
        s1[++t1]=data;
    }
    else{
        printf("\nOverflow");
    }
}

int pop_s1(){
    int item;
    if(t1!=-1){
        item=s1[t1--];
    }
}

void push_s2(int data){
    s2[++t2]=data;
}

int pop_s2(){
    int item;
    if(t2!=-1){
        item=s2[t2--];
        return item;
    }
}

int main(){
    int inp,item;
    printf("\nEnter max number of elements:");
    scanf("%d",&n);
    
    do{
        printf("\nEnter 1 to enqueue, 2 to dequeue all elements and 3 to stop:");
        scanf("%d",&inp);
        switch(inp){
            case 1:
                push_s1(item);
                break;
            case 2:
                //Pushing elements into st2 from st1
                while(t1!=-1){
                    push_s2(pop_s1());
                }
                
                //Dequeuing all the elements at once
                while(t2!=-1){
                    item=pop_s2();
                    printf("\nDequeued element :%d",item);
                }
                break;
            case 3:
                break;
        }
    }
    while(inp!=3);
}