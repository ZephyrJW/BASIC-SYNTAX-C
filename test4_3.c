#include <stdio.h>

int main(){
	char a[20];
	scanf("%s",a);

	int len = 0,i=0;

	while(a[i] != '\0'){
		len++;
		i++;
		}
	
	printf("%s, %d\n",a, len);
	
	return 0;
	}
