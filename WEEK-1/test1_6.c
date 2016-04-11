#include <stdio.h>

int main(){
	char a[] = "this is string a", b[]="this is string b";
	char *p1=a, *p2=b;
	void copy_string(char *, char *);
	printf("a: %s\nb: %s\n",a,b);
	
	copy_string(p1,p2);
	
	printf("after the copy:\na: %s\nb: %s\n",p1,p2);
	
	
	return 0;
	}

void copy_string(char *from, char *to){
	while((*to++=*from++)!='\0');
	
	}
