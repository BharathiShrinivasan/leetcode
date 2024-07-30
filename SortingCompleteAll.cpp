#include<stdio.h>
#include<cstdlib>
#define SIZE 10

void swap(int* ptr1, int* ptr2){
	int dummy=*ptr1;
	*ptr1=*ptr2;
	*ptr2=dummy;
}

void bubbleSort(int *array, int size){ // O(n^2)
	int noOfswap=0;
	do{
		noOfswap=0;
		for(int i=0,j=1;i<size-1;i++,j++)
		if(array[i]>array[j]){
			swap(&array[i],&array[j]);
			noOfswap++;
		}
	}while(noOfswap>0);
}

void selectionSort(int *array, int size){ // O(n^2)
	for(int i=0;i<size;i++){
		// pick the element and make this is min of whole rightside.
		int currentMin=array[i]; int indexToswap=-1;
		for(int j=i+1;j<size;j++){
		 // check all rightside elements
		 if(array[j]<currentMin){
		 	indexToswap=j; currentMin=array[j];
		 }
		}
		if(indexToswap!=-1) swap(&array[i],&array[indexToswap]);
	}
}

void mergeSort(int *array,int size){ // most respected sorting - O(n logn)
	if(size==1) return;
	else{
		// create a duplicate of array and split into 2 halves
		int *dupArray=(int*)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++)dupArray[i]=array[i];
		
		mergeSort(&dupArray[0],size/2); mergeSort(&dupArray[size/2],size-(size/2));
		
		// consider its sorted. need to merge two sorted arrray into out correct array
		int firstSortedArrayIndex=0,secondSortedArrayIndex=size/2;
		for(int i=0;i<size;i++){
			if(firstSortedArrayIndex<size/2 && secondSortedArrayIndex<size){ // check if noarray is exhausted both are ther yet to get read
				array[i]=dupArray[firstSortedArrayIndex]<dupArray[secondSortedArrayIndex]?dupArray[firstSortedArrayIndex++]:dupArray[secondSortedArrayIndex++];				
			}
			else{
				if(firstSortedArrayIndex==size/2){ // first array is exhausted just copy the whole second array
					array[i]=dupArray[secondSortedArrayIndex++];
				}
				else array[i]=dupArray[firstSortedArrayIndex++]; // second is exhausted, copy whole first
			}
		}
		free(dupArray);
	}
}

int main()
{
	int array[SIZE]={4,6,1,3,-6,4,6,9,10,-2};
	
	//bubbleSort(array,SIZE);
	//selectionSort(array,SIZE);
	mergeSort(array,SIZE);
	for(int i=0;i<SIZE;i++)
	printf("%d ",array[i]);
	
	return 1;
	
}
