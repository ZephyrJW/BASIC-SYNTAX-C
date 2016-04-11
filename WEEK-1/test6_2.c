//输入一个字符串，内有数字和非数字字符，如23a 345 b3.78，将其中连续的数字作为一个整数，一次存放到一个数组a中。


#include <stdio.h>

int _get_number(char input[20],int i,int j){
	int sum=0;
	int gap=1;
	for(int k=0;k<(j-i);k++){
		gap *= 10;
		}
	for(int k=i;k<=j;k++){
		sum += gap*(input[k]-'0');
		gap /=10 ;
		}
		return sum;
	}

int main(){
	int input_len;
	char input[20];
	for(int i=0;i<20;i++){
		scanf("%c",&input[i]);
//下面这句的本义是想记录输入长度，但是回车键也会计入到输入的字符串中，这样才能判定嘛，所以如果输入了b23，那么长度是0，1，2，3共四个
		if(input[i] == 10) {input_len = i; break;}
		}

	int a[10];
	int mark=0;
	int i=0;
	int x;
	while(i<input_len){
		if(input[i]>='0' && input[i]<='9'){
			for(int j=i;j<=input_len;j++){
				if((input[j]<'0'||input[j]>'9') || j==input_len){ 
					if(j==input_len && (input[j]>='0'&&input[j]<='9'))
						j++;
					x=j;
					break;
					}
				}
	//printf("lenth = %d, i = %d, j = %d\n",input_len,i,x);
			int number = _get_number(input,i,x-1);
			i=x;
			a[mark++] = number;
			}
		i++;
		}

		
	for(int i=0;i<mark;i++){
		printf("%d ",a[i]);
		}
	printf("\n");

	return 0;
}
