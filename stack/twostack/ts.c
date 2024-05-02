#include <stdio.h>
#define MAX 100
int arr[MAX],n,top1=-1,top2;

void push_st1(){
    int data;
    if(top1==(n/2)-1){
        printf("\n--Overflow--");
    }
    else{
        int d;
        printf("\nEnter data:");
        scanf("%d",&data);
        arr[++top1]=data;
    }
}

void push_st2(){
    int data;
    if(top2==n-1){
        printf("\n--Overflow--");
    }
    else{
        printf("\nEnter data:");
        scanf("%d",&data);
        arr[++top2]=data;
    }
}

int pop_st1(){
    if(top1==-1){
        printf("\nUnderflow");
        return -404; //Signal
    }
    else{
        int d=arr[top1--];
        return d; 
    }
}

int pop_st2(){
    if(top1==(n/2)-1){
        printf("\nUnderflow");
        return -404; //Signal
    }
    else{
        int d=arr[top2--];
        return d; 
    }
}

void traverse_st1(){
    if(top1==-1){
        printf("\nEmpty stack");
    }
    else{
        int i=top1;
        printf("\nStack:");
        while(i!=-1){
            printf("\n%d",arr[i]);
            i--;
        }
    }
}

void traverse_st2(){
    if(top2==(n/2)-1){
        printf("\nEmpty stack");
    }
    else{
        int i=top2;
        printf("\nStack:");
        while(i!=(n/2)-1){
            printf("\n%d",arr[i]);
            i--;
        }
    }
}

int main(){
    printf("\nEnter size of array:");
    scanf("%d",&n);
    top2=(n/2)-1;
    int ch1,ch2,item;
    do{
        printf("\nEnter 1 to perform operation in stack-1 or 2 in stack-2 or 3 to end:");
        scanf("%d",&ch1);
        switch(ch1){
            case 1:
                //Stack-1
                printf("\nEnter 1 to push, 2 to pop or 3 to traverse stack 1 or 4 to end:");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        //Push
                        push_st1();
                        break;
                    
                    case 2:
                        //Pop
                        item=pop_st1();
                        if(item!=-404){
                            printf("Popped element is %d",item);
                        }
                        break;
                    
                    case 3:
                        //Traverse
                        traverse_st1();
                        break;
                    
                    case 4:
                        break;
                }
                break;
            
            case 2:
                //Stack-2
                printf("\nEnter 1 to push, 2 to pop or 3 to traverse stack-2 or 4 to end:");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        //Push
                        push_st2();
                        break;
                    
                    case 2:
                        //Pop
                        item=pop_st2();
                        if(item!=-404){
                            printf("Popped element is %d",item);
                        }
                        break;
                    
                    case 3:
                        //Traverse
                        traverse_st2();
                        break;
                    
                    case 4:
                        break;
                }
                break;
            
            case 3:
                break;
        }
    }
    while(ch1!=3);
}