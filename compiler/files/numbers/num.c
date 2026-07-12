#include <stdio.h>

int main(){
    FILE *fp = fopen("../sample.txt", "r");
    FILE *fpw = fopen("output.txt", "a");
    char ch;
    while((ch = getc(fp)) != EOF) {
        int flag = 0;
        while((int)(ch)>=48 && (int)(ch)<=57 && ch!= EOF){
            putc(ch, fpw);
            ch = getc(fp);
            flag++;
        }
        if(flag!=0){
            putc('\n', fpw);
        }
    }
}