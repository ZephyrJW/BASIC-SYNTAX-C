#include <stdio.h>

int _strcmp(char *p1, char *p2){
		int res;
		while(*p1 != '\0'){
			if(*p2 == '\0') {res =  *p1; break;}
			if(*p1 != *p2) {res =  *p1-*p2; break;}
			//if(*p1 < *p2) {res =  *p2-*p1; break;}
			p1++;
			p2++;
			}
		if(*p1 == '\0' && *p2 != '\0') res =  *p2;
		if(*p2 == '\0') res =  0;
		return res;
	}

int main(){
	char *p1 = "BAD"; 
	char *p2 = "BOY";

	int res = _strcmp(p1,p2);
	printf("%d\n",res);
	
	return 0; 
	}
