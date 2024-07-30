#include<stdio.h>
#define MAX 5

int Que[MAX];
int entry=0,exit=0;
int noOfitems=0;

int insert(int x){
	if(noOfitems==MAX) return 0;
	else{
		Que[entry]=x;
		noOfitems++;
		entry=(entry+1)%MAX;
		return 1;
	}
}

int remove(){
	if(noOfitems==0){
		printf("no items to remove");
		return -1;
	}
	else{
		int i=Que[exit];
		exit=(exit+1)%MAX;
		noOfitems--;
		return i;
	}
}

int main()
{
	insert(45);
	insert(67);
	insert(99);
	printf("%d",remove());
	insert(100);
	printf("%d",remove());
	insert(55);
	insert(99);
	insert(100);
	insert(88);
	printf("%d",remove());
	printf("%d",remove());
	printf("%d",remove());
	printf("%d",remove());
	printf("%d",remove());
	printf("%d",remove());
	
}
