#include<stdio.h>

int StartingIndex(int nums[], int size, int target,int *iteration){
	
	int left=0,right=size-1;
	
	while(left<size && right>=0){ *iteration=*iteration+1;
		if(nums[left]>target || nums[right]<target || (left+1==right && nums[left]!=target && nums[right]!=target)) return -1;
		if(left>0 && nums[left]==target && nums[left-1]!=target) return left;
		else{
			if(right>0 && nums[right]==target && nums[right-1]!=target) return right;
			else{
				if(left==0 && nums[left]==target) return 0;
				else{
					if(nums[(left+right)/2]<target)left=(left+right)/2;
					else{
						right=(left+right)/2;
					}
					
				}
			}
		}

	}
	
	
}

int main(){
	const int size=8000;
	int nums[size]={2,2,2,2,4,4,5,5,5,5,5,5,6,6,7,7,7,8,9,15};
	int iteration=0;
	for(int i=0;i<size;i++)nums[i]=i;
	int result=StartingIndex(nums,size,6,&iteration);
	printf("%d\n i-%d",result,iteration);	
	
	return 1;
}
