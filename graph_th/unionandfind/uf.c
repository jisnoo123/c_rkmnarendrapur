//Not yet complete.Giving wrong output
#include <stdio.h>
#define MAX 100
int a[MAX];
int adj[MAX][MAX];

void makeset(int n){
    //Naming the vertices from 1 to n
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}

void inpedge(int n){
    printf("\n1 for yes and 0 for no");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                printf("\nIs there edge between vertices %d and %d ?: ",i,j);
                int inp;
                fflush(stdin);
                scanf("%d",&inp);
                switch(inp){
                    case 1:
                        adj[i][j]=1;
                        adj[j][i]=1;
                        break;
                    case 0:
                        adj[i][j]=0;
                        adj[j][i]=0;
                        break;
                    default:
                        printf("\nWrong input.Enter again");
                        j--;
                        break;
                }
            }
        }
    }
}

void un(int i,int j){
    //Unite two subsets
    a[i]=a[j];
}

int findset(int i,int j){
    if(a[i]!=a[j]){
        return 1;
    }
    else{
        return 0;
    }
}

void find(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                if(adj[i][j]==1){
                    if(findset(i,j)){
                        un(i,j);
                    }
                }
            }
        }
    }
}

void check(int n){
    int k=1,x=a[0];
    //Checks if graph is connected or not
    for(int i=2;i<=n;i++){
        if(x=a[i]){
            k++;
        }
    }
    if(k==1){
        printf("\nConnected graph");
    }
    else{
        printf("\nNot connected with k=%d",k);
    }
}
int main(){
    int n;
    printf("\nEnter number of vertices: ");
    scanf("%d",&n);
    //Making the subsets in an array
    makeset(n);
    //Taking the edges 
    inpedge(n);
    //Performing opn
    find(n);
    //Checking if graph is connected or not
    check(n);
}