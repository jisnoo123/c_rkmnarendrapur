//Insertion of an element into an array
#define NULL 0
int insertion(int *a, int l, int u, int p, int e){
    //Returns 0 if insertion not possible else returns 1
    int i;
    if(a[u]==NULL){
        printf("Array full insertion not possible");
        return 0;
    }
    else{
        i=u;
        while(i>p){
            a[i]=a[i-1];
            i--;
        }
        a[p]=e;
        return 1;
    }
}