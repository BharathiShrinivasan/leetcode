#include<stdio.h>

int EuclidMethod(int x, int y){
	int result=1;
	int min=x<y?x:y, max=x>y?x:y;
	while(max%min!=0){
		int temp=min;
		min=max%min;
		max=temp;
	}
	return min;
}

int main(){
	int x=320,y=132;
	printf("HCF- %d\n",EuclidMethod(x,y));
	printf("LCM- %d",(x*y)/EuclidMethod(x,y));
	float p=0.7;
	if(p<0.7) printf("hi");
	
	char *str="hai";
	str[0]='h';
	
	return 1;
}
