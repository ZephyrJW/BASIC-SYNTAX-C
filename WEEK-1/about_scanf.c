#include<stdio.h>

int main(){
	double d;
	char c;

	scanf("%lf", &d);
	printf("%.2f\n",d);
	getchar(); 
//上面输入的是一个double型加一个回车（换行符），double型被d接收，而回车会被 char 接收，所以这里必须加入一个getchar().
	scanf("%c",&c);
	printf("%c, %d\n",c,c);

	return 0;
	}
