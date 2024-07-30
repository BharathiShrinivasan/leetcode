#include<stdio.h>
#include<cstdlib>

int** threeSum(int* nums, int numsSize, int* returnSize,int **returnColumnSizes){
int columnSize=0;
int **result=(int**)malloc(sizeof(int*)*10);

int *ptr=NULL;
for(int i=0;i<numsSize;i++){
    for(int j=i+1;j<numsSize;j++){
        for(int k=j+1;k<numsSize;k++){
            if(nums[i]+nums[j]+nums[k]==0){
                // check if its already in previous
                result[columnSize]=(int*)malloc(sizeof(int)*3);
                ptr=result[columnSize];
                ptr[0]=nums[i];
                ptr[1]=nums[j];
                ptr[2]=nums[k];
                (*returnColumnSizes)[columnSize]=3;
                columnSize++;
            }
        }
    }
}
*returnSize=columnSize;
return result;
}

int main(){
	int array[6]={-1,0,4,2,-1,-4};
	int returnSize=0;
	int (**ptr);
	
	int col[10]={0};
	int *colptr=&col[0];
	int **returnColumnSizes=&colptr;
	
	ptr=threeSum(array,6,&returnSize,returnColumnSizes);
	printf("result size- %d\n",returnSize);
	
	for(int i=0;i<returnSize;i++)
	{
		for(int j=0;j<col[i];j++)
		printf("%d ",ptr[i][j]);
		printf("\n");
	}

/*	int *holder[4];
	int **ptr;
	ptr=holder;
	int a[3]={3,3,3}; int b[5]={5,5,-5,5,5}; int c[2]={2,2}; int d[1]={1};
	holder[0]=a; holder[1]=b; holder[2]=c; holder[3]=d;
	
	printf("a: &a-%d *a-%d a-%d\n",&a,*a,a);printf("b: address-%d data-%d\n",b,*b);
	printf("c: address-%d data-%d\n",c,*c);printf("d: address-%d data-%d\n",d,*d);
	
	printf("holder: address-%d, data-%d\n",holder,*holder);
	printf("ptr: address-%d, data-%d\n\n",&ptr,ptr);
	
	printf("address-%d ptr[1][2]=%d\n\n",&ptr[1][2],ptr[1][2]);
	
	int z[10][10]={{2,5,6,-9},{9,7,35}};

	int (*hld)[10]=z;
	printf("hld: address-%d, data-%d\n",&hld,hld);
	printf("z: address-%d, data-%d\n\n",z,*(z+0));
	printf("z[1][2]: address-%d, data-%d (z+(1*10+2))=%d *=%d\n\n",&z[1][2],z[1][2],(z+(1*10+2)),*((z+(1*10+2))));
	printf("hld+1 = %d, \n",hld+1);
	printf("hld[1][2]: address-%d, data-%d *(hld+12)=%d\n\n",&hld[1][2],hld[1][2],*(hld+12));
	printf("%d",*((int*)(z+1)+2));
	*/
	
	return 1;
}
