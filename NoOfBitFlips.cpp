#include<stdio.h>

int main(){
	int a=2,b=6,c=4;
    bool residueA,residueB,residueC;
    int flip=0;

    for(int i=1;i<=0x3FFFFFFF;i=i*2)
    {
        residueA=a&i;
        residueB=b&i;
        residueC=c&i;
		//printf("%d %d %d\n",residueA,residueB,residueC);
        if((residueA|residueB) != residueC)
            {
            	printf(".");
                if(residueC)
                    {
                        flip+=1;//printf("+1\n");
                    }
                else
                    {
                        if(residueA & residueB) flip+=2;
                        else flip+=1;
                    }
            }

    }
    
    printf("flip= %d",flip);

    return flip;

}
