#include<stdio.h>

int myAtoi(char * s){
	bool sign=false,startParse=false;
	unsigned int sum=0;

	for(int i=0;s[i]!='\0';i++){
	    if(s[i]>='0' && s[i]<='9'){ // 0-9 read
	        if(startParse==true){
	            int temp=sum;
	            sum=sum*10+int(s[i]-'0');
	            if(temp!=sum/10){sum=0xFFFFFFFF;break;} // overflow
	        }
	        else{
	            if(s[i]!='0'){
	                startParse=true; sum=int(s[i]-'0');
	                if(i>0)if(s[i-1]=='-')sign=true;
	            }
	        }
	    }
	    else{
	        if(startParse==true) break;
	    }
	}
	
    if(sign==true){
        return sum<=0x80000000?int(0-sum):0x80000000;
    }
    else{
        return sum<=0x7fffffff?int(sum):0x7fffffff;
    }

}

int main(){
	char input[]="+-12";
	printf("%d",myAtoi(input));
	return 1;
}
