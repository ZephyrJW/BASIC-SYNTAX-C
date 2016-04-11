#include <stdio.h>

int main(){
	char a[]="this is string a", b[] = "this is string b";
	void copy_string(char [], char []);

	printf("a = %s\nb = %s\n",a,b);
	copy_string(a,b);
	printf("after the copy operation:\n");
	printf("a = %s\nb = %s\n",a,b);
	
	
	
	return 0;
	}

void copy_string(char from[], char to[]){
	int i=0;
	while(from[i]!='\0'){
		to[i] = from[i];
		i++;
		}
		to[i] = '\0';
}
