#include<stdio.h>
#include<cstdlib>

void swap(int* ptr1, int* ptr2){
	int temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}

void sort1(int *array,int size) // Selection sorting
{
	for(int i=0;i<size-1;i++){
		int min=array[i];
		int *minptr=&array[i];
		
		for(int j=i+1;j<size;j++){
			if(array[j]<min){
				minptr=&array[j];
				min=array[j];		
			}
		}
		if(minptr!=&array[i]) swap(minptr,&array[i]);
	}
}

void sort2(int* array,int size) // merge sortings
{
	if(size<=2){
		if(size==1) return;
		else{ // size=2 [x,y]
			if(array[0]>array[1]){
				swap(&array[0],&array[1]);
				return;	
			}			
		}
	}
	else{
		int *dupArray=(int*)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++)dupArray[i]=array[i];
		
		sort2(&dupArray[0],size/2); sort2(&dupArray[size/2],size-(size/2));
		// merge those two sorted arrays
		int leftIndex=0,rightIndex=size/2;
		for(int i=0;i<size;i++)
		{
			if(leftIndex<size/2 && rightIndex<size){
				array[i]=dupArray[leftIndex]<dupArray[rightIndex]?dupArray[leftIndex++]:dupArray[rightIndex++];
			}
			else{
				if(leftIndex==size/2){
					array[i]=dupArray[rightIndex++];
				}
				else{
					array[i]=dupArray[leftIndex++];
				}
			}	
		}
		free(dupArray);
		return;		
	}
}

bool containsDuplicate(int* nums, int numsSize){
	sort2(nums,numsSize);
	for(int i=1;i<numsSize;i++){
		if(nums[i]==nums[i-1]) return true;
	}
	return false;
}

bool containsDuplicateOld(int* nums, int numsSize){
	for(int i=0;i<numsSize-1;i++)
	for(int j=i+1;j<numsSize;j++)
	if(nums[i]==nums[j])return true;
	return false;
}

int main()
{
	const int size=10;
	int array[size]={3,-2,0,4,6,5,8,8,7,-4};
	sort2(&array[0],size);
	for(int i=0;i<size;i++)
	{
	//	printf("%d ",array[i]);
	}
	const int sizes=100000;
	int nums[sizes]; for(int i=0;i<sizes;i++)nums[i]=i;
	//printf("%d",containsDuplicateOld(&nums[0],sizes)); // O(n^2)
	printf("%d",containsDuplicate(&nums[0],sizes)); // O(logn)
	return 1;
}
