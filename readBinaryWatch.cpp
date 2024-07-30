#include<stdio.h>
#include<cstdlib>


int noOfones(int x){
    int count=0;
    for(int i=0;i<6;i++){
        if(x&1)count++;
        x=x>>1;
    }

    return count;
}

void copyString(char* ptr,int hrs, int min){
    if(hrs>9){
        ptr[0]='1'; ptr[1]=(char)hrs%10+'0';
        ptr[2]=':';
        ptr[3]='0'+min/10; ptr[4]='0'+min%10;
        ptr[5]='\0';
    }
    else{
        ptr[0]=(char)hrs%10+'0';
        ptr[1]=':';
        ptr[2]='0'+min/10; ptr[3]='0'+min%10;
        ptr[5]='\0';
    }
}

char ** readBinaryWatch(int turnedOn, int* returnSize){
    char **ptr=(char**)malloc(sizeof(char*)*1000);
    *returnSize=0;

    for(int hrs=0;hrs<12;hrs++){
        for(int min=0;min<60;min++){
            if(noOfones(hrs)+noOfones(min)==turnedOn){
                char *temp=(char *)malloc(sizeof(char)*6);
                ptr[*returnSize]=temp;
                copyString(temp,hrs,min);
                *returnSize=*returnSize+1;
            }
        }
    }
    return ptr;
}

int main(){
	int returnSize_col=0;
	char** ptr;
	ptr=readBinaryWatch(3,&returnSize_col);
	for(int i=0;i<returnSize_col;i++)
	{
		printf("%s\n",ptr[i]);
	}
	free(ptr);
	return 1;
}
