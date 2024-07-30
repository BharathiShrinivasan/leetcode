#include<stdio.h>
bool isPalindrome(char * s){

    int startIndex=0,endIndex=0;
    for(;s[endIndex]!='\0';endIndex++);
    endIndex-=1;

    while(startIndex<endIndex){
        //get valid alphbet for start
        while(!((s[startIndex]<='9' && s[startIndex]>='0')||(s[startIndex]<='z' && s[startIndex]>='a')||(s[startIndex]<='Z' && s[startIndex]>='A')) && (startIndex<endIndex)) startIndex++;
        //get valid alphbet for end
        while(!((s[endIndex]<='9' && s[endIndex]>='0')||(s[endIndex]<='z' && s[endIndex]>='a')||(s[endIndex]<='Z' && s[endIndex]>='A'))&& (startIndex<endIndex)) endIndex--;
        //compare if not same its not pali
        char a=s[startIndex],b=s[endIndex];
        if((a<='Z' && a>='A'))a=a+('a'-'A');//smallizing
        if((b<='Z' && b>='A'))b=b+('a'-'A');//smallizing
        if(a!=b) return false;
        startIndex++; endIndex--;
    }
    return true;
}

int main(){
	char input[]="ab2a";

	printf("%d",isPalindrome(input));
	return 1;
}
