#include<stdio.h>
#include<cstdlib>

int** threeSum(int* nums, int numsSize, int* returnSize){
int* result[10]; int columnSize=0;

int *ptr=NULL;
for(int i=0;i<numsSize;i++){
    for(int j=i+1;j<numsSize;j++){
        for(int k=j+1;k<numsSize;k++){
            if(nums[i]+nums[j]+nums[k]==0){
                result[columnSize]=(int*)malloc(sizeof(int)*3);
                ptr=result[columnSize];
                ptr[0]=nums[i];
                ptr[1]=nums[j];
                ptr[2]=nums[k];
                printf("%d %d %d\n",ptr[0],ptr[1],ptr[2]);
                //returnColumnSizes[0][columnSize]=3;
                columnSize++;
            }
        }
    }
}
*returnSize=columnSize;
return (int**)result;
}

int main()
{
	int nums[] = {-1,0,1,2,-1,-4};
	int returnSize=0;
	int** ptr;
	ptr=threeSum(nums,6,&returnSize);
	printf("-\n");
	for(int i=0;i<returnSize;i++)
	{
		printf("%d %d %d\n",ptr[i][0],ptr[i][1],ptr[i][2]);
	}
	
	return 0;
}
