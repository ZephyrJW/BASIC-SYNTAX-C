#include <stdio.h>
#include <string.h>

int main(){
	char a[] = "number_of_lines";
	char *p = strtok(a,"_");
	char c[50];
	strcat(c,p);

	if(p){
		p = strtok("NULL","_");
		*p = *p - 32;
		strcat(c,p);
	}

	if(p){
		p = strtok("NULL","_");
		*p = *p - 32;
		strcat(c,p);
	}
	printf("%s\n",c);
	
	return 0;
	}
