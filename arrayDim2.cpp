#include<stdio.h>
#include<cstdlib>

/*
	int array[ROW][COLUMN]={0}; MemoryAllocation : 0,0|0,1|0,2...|0,COLUMN-1||1,0|1,2....||....||ROW-1,0|
	&array[row][column]=baseAddress+(row*COLUMN+column) ; baseAddress=&(0,0)
	Therefore, COLUMN is to be known as it directly involves in pointer-arthemetics/address calculation. THis is known via defining it in datatypes with this COLUMN
	
	int *x; pointer-x pointing to int-type or, x is a pointer holding address of an integer-type-data
	
	int **x; visualise as int *(*x) or a pointer pointing to int* type.
	int (*x)[2]; a pointer pointing to int[2] -> array of int with column=2.
	int *(*x)[2]; a pointer pointing to int*[2] -> array of int* with column=2.
	
*/

int main()
{
	int array[2][5]={{1,2,3,4,5},{10,15,20,25,30}}; // 5 column
	int x[2]={2,3}; // 1 coulmn
	int (*ptr)[5]; // pointer to point integer of 5 columns
	ptr=array; // put the address of 1st elemetn aka array
	
	
	int *ptr3[2]; // each ptr element points to a 1 column interger location
	ptr3[0]=x;
	
	int (*ptr1[5])[2]; // 2 column; each ptr element points/holds-1st-element-ka-address of 2 column integer
	ptr1[0]=&x;
	
	int q1[2]={2,3}, q2[4]={5,6,7};//column 1
	int *q[2];// array of pointers pointing to integer of 1column
	q[0]=q1; q[1]=q2;
	int **q4; // pointer pointing to (a pointer that points to integer of column 1)
	q4=(int **)&q; // type case to int** 
	printf("(*q4)[0]=%d (*q4)[1]=%d\n",(*q4)[0],(*q4)[1]);
	
	
	int (*k)[4];// pointer pointing to interger of 4 column width.
	k=&q2; printf("k[0][2]=%d\n",k[0][2]);
	
	int **r1; int w=22; int *wPtr=&w;
	r1=&wPtr;
	
	int **z1;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("<%d>-%d ",&array[i][j],array[i][j]);
		}	
		printf("\n");
	}

	printf("\n ptr[1][3]=%d",ptr[1][3]);
	//printf("%d",ptr[1][2]);
		
	return 0;	
}
