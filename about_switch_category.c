#include <stdio.h>

int main(){
	int score;
	scanf("%d",&score);

	switch(score){
		case 60 ... 100:
			printf("PASS\n");
			break;
		case 0 ... 59:
			printf("FAIL\n");
			break;
		default:
			printf("input error");
		}
	
	
	return 0;
	}
