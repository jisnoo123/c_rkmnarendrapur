#include<stdio.h>
#include<string.h>
int main(){
	char text[100],substr[100];
	int text_len,sub_len,j,i;
	puts("Enter the sentence: ");
	gets(text);
	puts("Enter the word to be searched: ");
	gets(substr);
	text_len=strlen(text);
	sub_len=strlen(substr);
	
	for(i=0;i<=text_len-sub_len;i++){
		for(j=0;j<sub_len;j++){
			if(text[i+j]==substr[j])
				continue;
			else 
				break;
		}
		if(j==sub_len)
			printf("present at %d onwards",i);
	}
}
