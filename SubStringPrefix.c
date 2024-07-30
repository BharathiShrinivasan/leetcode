#include<stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *outputPtr=(char *) malloc(sizeof(char)*10);
    for(int i=0;i<6;i++) // ith char in each words
    {
        char CharToCheck=*((strs[0])+i);
        bool checkCOndition=true;
        for(int j=0;j<strsSize;j++)
        {
            if(*((strs[j])+i)=='\0') {checkCOndition=false;break;}
            else if(*((strs[j])+i)!=CharToCheck) {checkCOndition=false;break;}
        }
        if (checkCOndition) outputPtr[i]=CharToCheck;
        else break;
    }
    return outputPtr;
}

int main()
{
	char *strs[] = {"Hello","hehe","hee"};
	char *ptr = longestCommonPrefix(&strs,3);
	printf("result - %s",*ptr);
	return 0;
}
