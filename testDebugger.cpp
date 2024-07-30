#include<stdio.h>

int x=2;

void callyou(int* i)
{
	x=x+*i;
	x++;
	*i=55;
	*i=4;
}

int main(){
	
	int a=34;
	
	for(int i=0;i<5;i++){
		a=a+10;
	}
	int* ptr=&a;
	*ptr=33;
	
	callyou(ptr);
	
	return 1;
}
