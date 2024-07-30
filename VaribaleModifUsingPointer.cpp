#include<stdio.h>
#include<cstdlib>

void foo(int * ptr)
{
	ptr[0]=-3;
}

int main()
{
	int *ptr;
	int array[]={2,4,6};
	
	foo(array);
	
	printf("%d %d %d",array[0],array[1],array[2]);
		
	return 0;
}
