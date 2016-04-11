//定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，注意闰年。
#include <stdio.h>
	struct date{
		int year;
		int month;
		int day;
		};

int _computeDays(struct date *p){
	int sum=0;
	int leapYear = ((p->year)%400==0) || (((p->year)%4==0)&&((p->year)%100 != 0));
	sum += p->day;
	
	for(int i=1;i<=p->month;i++){
	switch(i){
		case 1:
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			sum+=31;
			break;
		case 3:
			if(leapYear) sum += 29;
			else sum+=28;
			break;
		default:
			sum+= 30;
			break;
		}
		}
		return sum;
	}


int main(){
	struct date test;
	struct date *p = &test;
	printf("请输入年月日:");
	scanf("%d %d %d", &p->year, &p->month, &p->day);
	
	int res = _computeDays(p);
	printf("%d天\n",res);
	return 0;
	}
