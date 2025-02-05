//Converting multiple spaces into one
#include <stdio.h>
#include <string.h>
int main(){
	char s[100],ns[100];
	int i,c=0,f=0;
	puts("Enter a sentence : ");
	gets(s);
	int l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]!=' '){
			f=0;
			ns[c]=s[i];
			c++;
		}
		else{
			if(f==0){
				ns[c]=' ';
				c++;
			}
			f=1;
			continue;
		}
	}
	printf("New sentence\n");
	puts(ns);
}
