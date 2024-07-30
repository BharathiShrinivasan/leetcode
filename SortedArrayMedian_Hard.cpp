#include<stdio.h>
#include<cstdlib>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

	int totalsize=nums1Size+nums2Size, totalsize_half=(nums1Size+nums2Size)/2;
	double median=0.0;
	
	int center_elm=0,center_left_elm=0;
	int num1Index=0,num2Index=0;
	
	if(nums1==NULL && nums2!=NULL){
	    center_elm=nums2[totalsize_half];
	    center_left_elm=nums2[totalsize_half-1];
	}
	else{
	    if(nums2==NULL && nums1!=NULL){
	        center_elm=nums1[totalsize_half];
	        center_left_elm=nums1[totalsize_half-1];
	    }
	    else{
	        if(nums1==NULL && nums2==NULL) return 0;
	    }
	}
	
	for(int i=0;i<=totalsize_half;i++)
	{
	    center_left_elm=center_elm;
	
	    if(num1Index>=nums1Size){
	        center_elm=nums2[num2Index++];
	    }
	    else{
	        if(num2Index>=nums2Size){
	            center_elm=nums1[num1Index++];
	        }
	        else{
	            if(nums1[num1Index]<nums2[num2Index]){
	                center_elm=nums1[num1Index++];
	            }
	            else{
	                center_elm=nums2[num2Index++];
	            }
	        }
	    }
	    printf("%d ",center_elm);
	}
	
	if(totalsize%2==1){
	    return center_elm;
	}
	else{
	    return ((double)(center_elm+center_left_elm))/2;
	}
}

int main()
{
	int array1[5]={2,4,6,7,9};
	int array2[3]={2,3,3};
	double median=findMedianSortedArrays(array1,5,array2,3);
	printf("\nmedian=%f",median);
	return 0;
}
