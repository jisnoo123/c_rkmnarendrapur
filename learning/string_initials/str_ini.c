#include <stdio.h>
#include <string.h>
int main(){
	char a[100];
	int i=0;
	a[0]='a';
	for(;i<strlen(a);i++){
		if(a[i]=='a'){
			printf("%d",i);
			break;
		}
	}
}
