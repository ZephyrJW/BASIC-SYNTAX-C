#include <stdio.h>

int main(){
	char a[]="original string",b[20];
	char *p1=a,*p2=b;

	for(;*p1!='\0';p1++,p2++){
		*p2 = *p1;
		}
	*p2 = '\0';
	
	printf("string b is :%s\n  ",b);

	return 0;
	}
