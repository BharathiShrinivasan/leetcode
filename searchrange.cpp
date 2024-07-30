#include<stdio.h>
#include<cstdlib>

int searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left=0,right=numsSize-1,index=(numsSize-1)/2;
    
    while(nums[index]!=target){
		if(nums[left]>target || nums[right]<target) return -1;
		if(right-left >=2){
	    	if(nums[index]<target){
	    		left=index+1;
	    		index=(right+left)/2;
			}
			else{
				right=index-1;
				index=(right+left)/2;
			}
		}
		else{
			if(right==left) return -1;
			else{
				if(nums[right]==target) return right;
				else return -1;
			}
		}
		*returnSize=*returnSize+1;
	}
	
    return index;
} 

int binarySearch(int arr[], int l, int r, int x,int* returnSize)
{
    while (l <= r) {
    	*returnSize=*returnSize+1;
    	
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}

int main(){
	//const int size=20;int nums[size]={-2,-2,-2,-1,0,0,0,2,3,3,3,3,4,4,6,6,7,7,8,8};
	//const int size=10;int nums[size]={3,3,4,4,6,6,7,7,8,8};
	const int size=5;int nums[size]={0,6,7,7,8};
	int returnSize=0;
	//int ptr=searchRange(nums,size,5,&returnSize);
	int ptr=binarySearch(nums,0,size-1,5,&returnSize);
	printf("result %d\niterations %d",ptr,returnSize);
	
	return 1;
}
