//sorting a list of names alphabetically
#include <stdio.h>
#include <string.h>
char a[100][100];
int n;
void reorder(){
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
	int n,i;
	puts("Enter number of names: ");
	scanf("%d",&n);
	
	//Entering names in a 2D character array
	for(i=0;i<n;i++){
		puts("Enter name: ");
		fflush(stdin);
		gets(a[i]);
	}
	
	reorder();
	
	//Sorting completed
	
	//Displaying the array elements
	printf("\nDisplaying sorted names: \n\n");
	for(i=0;i<n;i++){
		puts(a[i]);
	}
}
