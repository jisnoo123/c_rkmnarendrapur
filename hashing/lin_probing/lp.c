/* Use h(X) = X mod 10 as the hash function and linear probing as the method 
of collision resolution */

#define MAX 10
#include <stdio.h>

int a[MAX], e, n=10;

int h(int X){
    // Hash function
    return X % 10;
}

void init(){
    //Initialize the whole array with -1, which indicates free space
    for(int i=0; i<n; i++){
        a[i] = -1;
    }
}

void linear_probing(int pos, int e){
    int p = (pos + 1)%10;
    while(a[p]!=-1 && p!=pos){
        p = (p+1)%10;
    }

    if(a[p]==-1){
        printf("\nInserting in index %d",p);
        a[p] = e;
    }
    else if(p==pos){
        printf("\nNo free space found to insert %d", e);
    }
}

void input(){
    printf("\nEnter element:");
    scanf("%d",&e);
    int pos = h(e); //Position given by hash function

    if(a[pos] == -1){
        //Free space
        a[pos] = e;
    }
    else{
        printf("\nCollision\nInitiating linear probing\n");
        //Use linear probing
        linear_probing(pos, e);
    }
}

void search(int key){
    int pos = h(key);

    if(a[pos]==key){
        printf("Found at index %d", pos);
    }
    else{
        //Forward searching
        int p = (pos+1)%10;
        while(a[p]!=-1 && p!=pos){
            if(a[p]==key){
                printf("\nFound at index %d", p);
                return;
            }
            p = (p+1)%10;
        }

        printf("\nNot found");
    }
}

void display(){
    printf("\nElements are:\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int ch,key;
    init();

    do{
        printf("\nEnter 1 to insert, 2 to search, 3 to display and 4 to end\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                input();
                break;
            
            case 2:
                printf("\nEnter key:");
                scanf("%d", &key);
                search(key);
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