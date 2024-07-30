#include<stdio.h>

char findTheDifference(char * s, char * t){
    int i=0,j=0,sum=0;
    while(t[i]!='\0'||s[j]!='\0'){

        if(t[i]!='\0'){
            sum+=(int)t[i];
            i++;
        }
        if(s[i]!='\0'){
            sum-=(int)s[j];
            j++;
        }
        
    }
    return (char)sum;
}

int main(){
	char a[]="abc";
	char b[]="cbda";
	
	findTheDifference(a,b);
	return 1;
}
