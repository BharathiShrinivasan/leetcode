#include<stdio.h>
#include<cstdlib>
/*********** need to fix ****************/
#define arraySize 6

char globaldata[6]={'\0'}; 
int counter=0;

void permute(char *data, int index){
	if(*data=='\0'){
		globaldata[index]='\0';
		printf("%s\n",globaldata);
		counter++;
		return;
	}
	char tempdata[arraySize];
	for(int i=0;data[i]!='\0';i++){
		int k=0;
		for(int j=0;data[j]!='\0';j++){
			if(j!=i){
				tempdata[k++]=data[j];
			}
		}
		tempdata[k]='\0';
		globaldata[index]=data[i];
		permute(tempdata,index+1);
	}
	return;
}


int main(){
	char data[arraySize+1]={'A','B','C','D','E','F','\0'};
	permute(data,0);
	printf("counter - %d",counter);
	return 1;
}
