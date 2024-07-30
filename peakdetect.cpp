#include<stdio.h>

int findPeakElement(int* nums, int numsSize){
    for(int i=0,j=numsSize-1;i<=j;i++,j--){
       
        if((i+1<numsSize?nums[i]>nums[i+1]:true) && (i-1>=0?nums[i]>nums[i-1]:true)) return i;
        if((j+1<numsSize?nums[j]>nums[j+1]:true) && (j-1>=0?nums[j]>nums[j-1]:true)) return j;
    }
    return 0;
}

int findPeakElement_Efficient(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] < nums[mid + 1]){
            left = mid + 1;
        }else{
            right = mid;   
        }
    }
    return left;
}

int main(){
	const int size=4;
	int array[4]={1,-4,-3,1};
	printf("%d",findPeakElement(&array[0],size));
	//printf("%d",findPeakElement_Efficient(&array[0],size));
	return 1;
}
