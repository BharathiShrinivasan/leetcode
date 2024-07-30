#include<stdio.h>

int main(){
	int a = 30, b = 40;
	int min = b ^ ((a ^ b) & -(a < b)); // Max of a and b
	int max = a ^ ((a ^ b) & -(a < b)); // Min of a and b
	
	printf("max= %d, min= %d",max,min);
	return 1;
}
