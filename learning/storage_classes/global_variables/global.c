#include <stdio.h>
int a;
void  func1();
void func2();
int main(){
    a=10;
    func1();
    printf("Main function a=%d",a);
}
void func1(){
    a=1;
    func2();
    printf("Function 1 a=%d",a);
}
void func2(){
    int a=100; //Local variable
    printf("Local variable a=%d",a);
}