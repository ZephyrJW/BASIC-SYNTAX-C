#include <stdio.h>
#include <stdlib.h>

int main(){
	char *p = (char *)malloc(50*sizeof(char));

	gets(p);
	int upper_count=0, lower_count=0, space_count=0, num_count=0,other=0;
	int i=0;
	while(p[i] != '\0'){
		if((p[i]-'A')>=0 && (p[i]-'Z')<=0) upper_count++;
		else if((p[i]-'a')>=0 && (p[i]-'z')<=0) lower_count++;
		else if(p[i] == ' ') space_count++;
		else if((p[i]-'0')>=0 && (p[i]-'9')<=0) num_count++;
		else other++;
		i++;
		}
	
	printf("大写字母%d个，小写字母%d个，空格%d个，数字%d个，其他%d个\n", upper_count, lower_count, space_count, num_count, other);
	
	
	
	return 0;
	}
