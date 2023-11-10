//To illustrate automatic or local variables
void func1(){
	int m=1;
	func2();
	printf("Function 1 m=%d",m); //Second output
}
void func2(){
	int m=2;
	printf("Function 2 m=%d",m); //First output
}
int main(){
	int m=1000;
	func1();
	printf("Main function m=%d",m); //Third output
}
