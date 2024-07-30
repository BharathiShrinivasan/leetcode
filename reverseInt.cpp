#include<stdio.h>

int reverse(int x){
// x can be (-0x8000 0000 to 0x7fff ffff)
unsigned int PosifiedInput=x>0?x:0-(unsigned int)x;
bool signbit=x<0?true:false;

unsigned int result=0;
for(;PosifiedInput>0;PosifiedInput/=10){
	unsigned int temp=result;
	result=result*10+PosifiedInput%10;
	if(temp!=((result-PosifiedInput%10)/10)){
		// overflow occured in unsigned int addition
		return 0;
	}
	if((signbit && result>0x80000000) || (signbit==false && result>0x7fffffff)) return 0;
	//printf("posifiedInput=%u result=%u | temp=%u recreateOldResult=%u\n",PosifiedInput,result,temp,);	
}

return signbit?0-result:result;
}

int main(){
	int x=1534236469;
		//2147483648
	printf("%d",reverse(x));
	
	return 1;
}
