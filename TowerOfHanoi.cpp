#include<stdio.h>

// MOVE (how_many,fromWhere,ToWhere,via)

void Move(int size,int src, int dest, int aux){
	if(size==1){
		
		printf("move - from Tower%d to Tower%d\n",src,dest);
		return;
	}
	else{
		Move(size-1,src,aux,dest);
		printf("move - from Tower%d to Tower%d\n",src,dest);
		Move(size-1,aux,dest,src);
	}
}

int main(){
	
	Move(3,0,2,1); // 3 items from Tower0 -> Tower2	
	return 1;
}
