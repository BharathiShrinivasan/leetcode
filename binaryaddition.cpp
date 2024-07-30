#include<stdio.h>
#include<cstdlib>

char * addBinary(char * a, char * b){
    int aLen=0,bLen=0,rLen=0;
    
    while(a[0]=='0'&&a[1]!='\0')a=&a[1];
    while(b[0]=='0'&&b[1]!='\0')b=&b[1];
    
    while(a[aLen++ +1 ]!='\0');
    while(b[bLen++ +1 ]!='\0');
    rLen=aLen>bLen?aLen+1:bLen+1;
    
    char *result=(char*)malloc(sizeof(char)*(rLen+1));
    result[rLen]='\0';
    int carry=0;

    for(int i=rLen-1;i>=0;i--){
        int sum=0;
        if(aLen>=1){ sum+=a[aLen-- -1]-'0';}
        if(bLen>=1){ sum+=b[bLen-- -1]-'0';}
        if(carry==1){ sum+=1;}
        result[i]=sum%2==1?'1':'0';
        carry=sum/2;
    }
    
    while(result[0]=='0'&&result[1]!='\0')result=&result[1];
    /*
    for(int i=0;i<rLen;i++){
        if(result[i]!='0'){
        	result=&result[i];
            break;
        }
    }*/
    
    return result;
}

int main()
{	char a[]="001111",b[]="0001";
	char *ptr=addBinary(a,b);
	printf("%s",ptr);

	return 1;
}
