#include<stdio.h>

int removeDuplicates(int* nums, int numsSize){
int ResultLength=numsSize;
int oldnum=nums[0];

for(int i=1;i<numsSize;i++)
{
	printf("i= %d\n",i);
    if(nums[i]==oldnum)
    {
        int j;
        for(j=0;nums[i+j]==oldnum;j++){
            if(i+j+1==numsSize){
            	ResultLength-=(j+1);
            	return ResultLength;
			}
        }
        for(int k=0;k<j;k++)nums[k+i]=nums[i+j];
        //ResultLength-=1;
        oldnum=nums[i+j];
    }
    else {
    	oldnum=nums[i];
	}
	
	for(int q=0;q<numsSize;q++)
	printf("%d,",nums[q]);	
	printf("\n");

}

return ResultLength;

}

int removeDuplicates1(int* nums, int numsSize){
int oldnum=nums[0];
int resultIndex=1;

for(int i=1;i<numsSize;i++)
{
	if(nums[i]!=oldnum){
		nums[resultIndex]=nums[i];
		oldnum=nums[i];
		resultIndex++;
	}
}

return resultIndex;

}

int main()
{
	int nums[18]={-1,0,0,1,2,2,2,3,4,4,5,6,6,7,8,9,10,10};
	int numsSize=18;
	//int k=removeDuplicates(nums,numsSize);
	int k=removeDuplicates1(nums,numsSize);
	
	printf("\n");
	for(int i=0;i<k;i++)
	printf("%d,",nums[i]);	
	
	return 1;
}
