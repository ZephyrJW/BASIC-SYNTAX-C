#include <stdio.h>
#include <string.h>

int main(){
	char a[] = "number_of_lines";
	char *p;
	p = strtok(a,"_");
	//可以用if(p)来判定是否找到了，在这里我知道有三段，省略了
	printf("%s\n",p);

	p = strtok(NULL,"_");
	printf("%s\n",p);

	p = strtok(NULL,"_");
	printf("%s\n",p);
	
	
	return 0;
	}
