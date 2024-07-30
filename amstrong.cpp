#include<stdio.h>

int power(int x,int y){
	int result=1;
	for(int i=0;i<y;i++)
	result*=x;
	return result;
}
	
int main(){
	int input=8732;
	//printf("%d",power(5,1));
	
	int NoOfDigit=0;
	int temp=input;
	while(temp){
		NoOfDigit++;
		temp/=10;
	}
	int sum=0;
	while(input){
		sum+=power(input%10,NoOfDigit);
		input/=10;
	}
	
	printf("%d",sum);
	
	return 1;
}

