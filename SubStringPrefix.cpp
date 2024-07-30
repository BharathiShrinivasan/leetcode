#include <stdio.h>
#include <cstdlib>

char * longestCommonPrefix(const char ** strs, int strsSize){
    char *outputPtr=(char *) malloc(sizeof(char)*10);
    for(int i=0;i<6;i++) // ith char in each words
    {
        char CharToCheck=strs[0][i];
        bool checkCOndition=true;
        for(int j=0;j<strsSize;j++)
        {
            if(strs[j][i]=='\0') {checkCOndition=false;break;}
            else if(strs[j][i]!=CharToCheck) {checkCOndition=false;break;}
        }
        if (checkCOndition) {
        	outputPtr[i]=CharToCheck;
        	printf("%c",CharToCheck);
		}
        else {
        	outputPtr[i]='\0';
			break;
		}
    }
    return outputPtr;
}

int main()
{
	const char* strs[] = {"hello","helhe","hele"};
	const char** list;
	list = strs;
	//const char* str="Hello";
	
	//printf("%c",*(list[2]+1));
	
	//char *ptr = longestCommonPrefix(list,3);
	
	//printf("result - %s",ptr);
	return 0;
}
