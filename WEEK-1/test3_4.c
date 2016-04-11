#include <stdio.h>
#include <string.h>


//从大到小排列
void sort(char *p[]){
	int i,j,k;
	char *temp;
	for(i=0;i<2;i++){
		k=i;
		for(j=i+1;j<3;j++){
			if(strcmp(p[k],p[j])<0) k=j;
			}
		if(k!=i){
			temp = p[i];
			p[i] = p[k];
			p[k] = temp;
			}
		}
	}


int main(){
	char *string[] = {"Arizona","California","New York"};

	sort(string);

	for(int i=0;i<3;i++){
		printf("%s  ",*(string+i));
		}
	printf("\n");
	
	
	return 0;
	}
