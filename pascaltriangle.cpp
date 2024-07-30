#include<stdio.h>
#include<cstdlib>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **resultptr=(int**)malloc(sizeof(int*)*numRows);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(numRows*sizeof(int));

    for(int i=0;i<numRows;i++){
        resultptr[i]=(int*)malloc((i+1)*sizeof(int));
        (*returnColumnSizes)[i]=i+1;
        for(int j=0;j<(i+1);j++){
            if(j==0 || j==i)(resultptr[i])[j]=1;
            else{
                (resultptr[i])[j]=(resultptr[i-1])[j-1]+(resultptr[i-1])[j];
            }
        }
        *returnSize=*returnSize+1;
    }
    return resultptr;
}


int main(){
	int returnSize=0;
	int *colsize; // colsize -> [no_col_row0, no_col_row1...]
	//int *result[30]; // result[0]->{1}, result[1]->{1,1}, result[2]->{1,2,1} ...
	int noOfrows=9;
	/*returnSize=2;
	colsize=(int*)malloc(sizeof(int)*returnSize);
	colsize[0]=3;colsize[1]=5;
	result[0]=(int*)malloc(sizeof(int)*3);
	result[1]=(int*)malloc(sizeof(int)*5);
	(result[0])[0]=45;(result[0])[1]=49;(result[0])[2]=48;
	(result[1])[0]=91;(result[1])[1]=99;(result[1])[2]=98;(result[1])[3]=95;(result[1])[4]=97;*/
	int **result=generate(noOfrows, &returnSize, &colsize);
	
	for(int i=0;i<returnSize;i++){
		for(int j=0;j<colsize[i];j++){
			printf("%d ",(result[i])[j]);
		}
		printf("\n");
	}
	
	
	
	return 1;
}

