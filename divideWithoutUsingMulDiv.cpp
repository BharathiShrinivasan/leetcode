#include<stdio.h>

int divide(int dividend, int divisor){

int resultFloor=0;

bool signOfResult=false; // +ve
if((dividend<0) != (divisor<0)) signOfResult=true;

/*
	consider the corner cases - if 32-bit then signed would be -2^31,0,2^31-1 so -2^31 -> can't be changed to 2^31 as it can be put in 32-bit signed number.
	so in case numerator or denominator == corner case need spl stuff-
*/

if(dividend&0x80000000){
    if(dividend==0x80000000) { // numerator is -2^31
    	if(divisor>0){ // denominator is +ve
    		dividend=0-(dividend+divisor); resultFloor++;
		}
		else{
			if(divisor==0x80000000) return 1;
			else{
				dividend=0-(dividend-divisor); resultFloor++;
			}
		}    
	}
    else dividend = 0-dividend;
}
if(divisor&0x80000000){
    if(divisor==0x80000000){
    	return 0;    	
	} 
    else divisor=0-divisor;
} 

/*if(dividend<0){
	if()
	dividend = 0-dividend;
}
if(divisor<0) divisor=0-divisor; */

for(;dividend-divisor>=0;resultFloor++){
	dividend=dividend-divisor;
}

if(signOfResult){ // neg result
    return 0-resultFloor;
}
else return resultFloor;
}

int divide1(int dividend, int divisor){
		
	bool signOfResult=false; // +ve
	if((dividend<0) != (divisor<0)) signOfResult=true;
	
	unsigned int num=0,den=0;
	if(dividend<0){
		if(dividend==0x80000000) // -(0x80000000) = same in unsigned.
		num=0x80000000;
		else{
			num=(unsigned int)((int)0-dividend);
		}
	}
	else num=(unsigned int) dividend;
	
	if(divisor<0){
		if(divisor==0x80000000) // -(0x80000000) = same in unsigned.
		{
			den=0x80000000;	
		}
		
		else{
			den=(unsigned int)((int)0-divisor);
		}
	}
	else den=(unsigned int) divisor;
	
	printf("%u / %u \n\n",num,den);
	
	// (0-2^31 / 1-2^31) as 2^31 is max integer possible from (int) datatype.
	unsigned int resultFloor=0;
	while(num>=den){
		unsigned int digit=0; unsigned int factorResult=1;
		printf(".");
		if(den<0x80000000){
			for(digit=0;num>(den<<digit);digit++){printf("* num=%u digit=%u den<<digit=%u\n",num,digit,den<<digit);factorResult=factorResult<<1;}
		}
		
		if(digit>0){
			num=num-(den<<(digit-1));
			resultFloor+=(factorResult>>1);	
		}
		else{
			num=num-den;
			resultFloor+=1;	
		}
		
		printf("%u / %u and result=%u\n",num,den,resultFloor);
	}
	
	if(resultFloor>=0x80000000 ){
		if(signOfResult==false)		return 0x7FFFFFFF;
		else return 0x80000000;
	}
	
	return signOfResult?(int)0-(int)resultFloor:(int)resultFloor;
}


int divide2(int dividend, int divisor){
	unsigned int den,num;
	bool negOutput= (divisor<0 == dividend<0) ? false:true;
	
	dividend<0?num=-dividend:num=dividend;
	divisor<0?den=-divisor:den=divisor;
		
	int Max_SL=0;
	while(den<num){ // check the Max shiftleft denominator that exceeds the numerator
		den=den<<1;
		Max_SL++;
	}
	
	printf("start> Max_SL=%u den=%u\n",Max_SL,den);
	unsigned int output=0;
	int shift=Max_SL;
	for(;shift>=0;shift--)
	{
		if(num>=den){
			output+=(1<<shift);
			num=num-den;
			den=den>>1;
		}
		else den=den>>1;
		printf("shift=%u output=%u num=%u\n",shift,output,num);
	}	
	
	if(output==0x80000000 && negOutput==false) return 0x80000000-1;
	
	return negOutput?-output:output;
}


int main(){
	int x=-2147483648,y=-1;//-2147483648, y=1; // x/y
	//int result= divide(x,y);
	int result=divide2(x,y);
	printf("\nresult- %d\nactual- %d",result,x/y);
	return 0;
}
