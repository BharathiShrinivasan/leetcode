#include<stdio.h>

int main(){
	int a=2,b=6,c=4;
    int ans=0;
    while(a!=0 | b!=0 | c!=0){
        if((c&1)==1){
            if((a&1)==0 && (b&1)==0){
                ans++;
            }
        }
        else{
            ans+=(b&1)+(a&1);
        }
        a>>=1;
        b>>=1;
        c>>=1;
    }
    printf("flip= %d",ans);

    return 1;

}
