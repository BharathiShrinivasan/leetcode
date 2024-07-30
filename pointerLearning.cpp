#include<stdio.h>

int main()
{
	int set1[5]={1,2,3,4,5};
	int set2[2]={-1,-2};
	int set3[3]={11,12,13};
	int set4[10]={9,9,9,9,9,9,9,9,9,9};
	int col[4]={5,2,3,10};
	int *colptr=&col[0];
	
	int* holder[4]={&set1[0],&set2[0],&set3[0],&set4[0]};
	int* *ptr=&holder[0];
	int* *colsp=&colptr;
	//printf("%d",(*colsp)[3]);
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<(*colsp)[i];j++)
		{
			printf("%d ",ptr[i][j]);
		}
		printf("\n");
	}
	
	return 1;
}
