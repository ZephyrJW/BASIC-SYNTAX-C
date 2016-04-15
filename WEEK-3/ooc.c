//c语言可以通过指向函数的指针完成面向对象的性质操作
#include <stdio.h>

void display(int a, char *b){
	printf("name: %s, age: %d\n", b, a);
	}

void student(int age, char *name, void (*op)(int a, char *b)){
	op(age, name);
	}


int main(){
	int age = 15;
	char name[20] = "xiaoMing";
	void (*op)(int a, char *b) = display;
	student(age, name, op);

	return 0;
	}
