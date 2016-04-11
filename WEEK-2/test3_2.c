//将number_of_lines转换成numberOfLines。不同的命名规则。
#include <stdio.h>
#include <string.h>

int main(){
	char a[] = "number_of_lines";
	char *p = strtok(a, "_");
	int count = 1;
	char b[50];
	strcat(b, p);

	while(p){
		if(count == 1){
			count++;
			p = strtok(NULL, "_");
			continue;
			}
		*p = *p - 32;
		strcat(b, p);
		p = strtok(NULL, "_");
		}
	
	printf("%s\n",b);
	return 0;
	}
