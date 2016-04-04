#include <stdio.h>

int main(){
	char a[] = "Hello string";

	printf("%s\n",a);
	printf("%c\n",a[6]);

	char *p = &a[0];
	for(int i=0;i<5;i++){
		printf("%c",*(p+i));
		}
	printf("\n");

	char *s = a;
	printf("%s\n", s);

	return 0;
	}
