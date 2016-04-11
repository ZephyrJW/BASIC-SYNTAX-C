//一班的a,b,c和二班的x,y,z进行乒乓球比赛。已知a不和x比，b不和x,z比,请打印对战表。


#include <stdio.h>

int main(){
	char a,b,c;

	for(a='x'; a<='z'; a++){
		for(b='x';b<='z';b++){
			for(c='x';c<='z';c++){
				if(a!=b && a!=c && b!=c && a!='x' && b!='x' && b!='z'){
					printf("a--%c, b--%c, c--%c\n",a,b,c);
					}
				}
			}
		}

	
	
	
	return 0;
	}
