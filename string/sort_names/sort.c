//sorting a list of names alphabetically
#include <stdio.h>
#include <string.h>
void reorder(int n , char a[][100]){
	char temp[100];
	int j , pass;
	for(pass=0;pass<n;pass++){
		for(j=0;j<n-pass;j++){
			if(strcmp(a[j],a[j+1])>0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
}
int main(){
	char a[100][100];
	int n,i;
	puts("Enter number of names: ");
	scanf("%d",&n);
	
	//Entering names in a 2D character array
	for(i=0;i<n;i++){
		puts("Enter name: ");
		fflush(stdin);
		gets(a[i]);
	}
	
	reorder(n, a);
	
	//Sorting completed
	
	//Displaying the array elements
	
	for(i=0;i<n;i++){
		puts(a[i]);
	}
}
