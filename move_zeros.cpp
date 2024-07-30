#include<stdio.h>

void moveZeroes(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            for(int j=i+1;j<numsSize;j++){
                if(nums[j]!=0){
                    int temp=nums[j];
                    nums[j]=0;
                    nums[i]=temp;
                    break;
                }
            }
        }
    }
}

int main(){
	int array[10]={-2,0,3,4,0,0,3,5,0,8};
	//moveZeroes(array,10);
	int UniIndex=-1;
    for(int i=0;i<10;i++){
    	if(array[i]!=0){
			UniIndex++;
			if(i!=UniIndex){
				array[UniIndex]=array[i];
				array[i]=0;
			}
        }
    }
    
	for(int i=0;i<10;i++)
	printf("%d ",array[i]);
	//printf("%d",findPeakElement_Efficient(&array[0],size));
	return 1;
}
