#include<stdio.h>
#include<cstdlib>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int *result1;
result1=(int*)malloc(20*sizeof(int));//result[2];
for(int i=0;i<numsSize;i++)
{
	//printf(".");
    for(int j=i+1;j<numsSize;j++)
    {
    	//printf(".");
        if(nums[i]+nums[j]==target){
            result1[0]=i; result1[1]=j;
            //printf("%d,%d",nums[i],nums[j]);
            break;
        }
    }
}
//printf("%d,%d",result1[0],result1[1]);
//*returnSize=2;  //<=== this is buggy as it tries to assess memory which is not created inthe first-place!..
*returnSize=2;
return result1;
}


int main()
{
	int array[]={2,7,3,4};
	int size;
	int* result;
	//printf("hi");
	result=twoSum(array, 4, 10,&size);
	printf("%d,%d size-%d",result[0],result[1],size);
	free(result);
	return 0;
}
