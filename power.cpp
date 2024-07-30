#include<stdio.h>
int q=0;
double pow(double x, int n) // x^n
{ 
	if(x==1) return 1;
	if(x==0) return 0;
	if(x==-1) return n%2?-1:1;
	if(n==0) return 1;
	if(n==1) return x;
	if(n==-1) return 1/x;
	
	double halfpow=pow(x,n/2);
	printf("n=%d pow(x,n/2)=%f\n",n,halfpow);
	return n%2==0?halfpow*halfpow:halfpow*halfpow*(n>0?x:1/x);
}
int main()
{
	printf("%f\n\n",pow(34.00515,-3));
	double res=1/34.00515;
	printf("%f ",res);
	res=res/34.00515;printf("%f ",res);
	res=res/34.00515;printf("%f ",res);
	
	return 1;
}
