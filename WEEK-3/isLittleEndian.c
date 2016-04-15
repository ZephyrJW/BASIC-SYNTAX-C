#include <stdio.h>

//判断是否为小端字节序
//a. 用联合体解决
union ut {
	int a;
	char b;
	};

int isLittleEndian1 (){
	union ut test;
	test.a = 1;
	return (int)test.b;
	}
//b. 用指针解决
int isLittleEndian2 (){
	int a = 1;
	return *(char *)&a;
	}


int main(){
	printf("%d\n", isLittleEndian1());
	printf("%d\n", isLittleEndian2());
	
	return 0;
	}
