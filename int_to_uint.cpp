#include<stdio.h>
int main()
{
	int x=0x7fffffff;//0x80000000;
	unsigned int y=x>0?x:0-(unsigned int)x;
	y=0x80000000;//0x80000000;
	x=y;
	printf("%d",x);
	return 1;
}
