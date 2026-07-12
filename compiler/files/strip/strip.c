#include <stdio.h>

int main(){
    FILE *fp = fopen("../sample.txt", "r");
    FILE *fpw = fopen("output.txt", "a");
    char ch;
    while((ch = getc(fp)) != EOF) {
        if(ch=='\n'){
            continue;
        }
        char next;
        putc(ch, fpw);
        if(ch == ' '){
            while(((next = getc(fp)) == ' ' || next == '\n') && next!= EOF){
                continue;
            }
            putc(next, fpw);
        }
        
    }
}