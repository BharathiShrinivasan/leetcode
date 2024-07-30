#include<stdio.h>
int result=0;
void climb(int steps){
    if(steps==1){
        result++; return;
    }
    if(steps==2){
        result+=2; return;
    }
    climb(steps-1);
    climb(steps-2);
    return;
}

int climbStairs(int n){
    result=0;    
    climb(n);
    return result;
}
extern int p;

int main(){
	int p=0;
	printf("%d",climbStairs(36));
	int n=2,m=4;
	printf("\n%d",n*++m||m+2);
	return 1;
}
