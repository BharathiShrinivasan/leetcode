#include<stdio.h>

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int prev=1,prev_prev=0;
    for(int i=2;i<=n;i++){
        int temp=prev;
        prev=prev+prev_prev;
        prev_prev=temp;
    }
    return prev;

}

int main(){
	int size=40000;
	printf("%d",fib(size));
	//printf("%d",findPeakElement_Efficient(&array[0],size));
	return 1;
}
