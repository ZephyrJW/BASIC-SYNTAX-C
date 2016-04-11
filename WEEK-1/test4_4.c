#include <stdio.h>

int main(){
	char from[100];
	scanf("%s", from);

	char to[100];
	int m = 5;
	int j=0;
	
	for(int i=5; from[i] != '\0';i++){
		to[j] = from[i];
		j++;
		}
	to[j] = '\0';
	
	printf("%s",to);	
	
	
	return 0;
	}
