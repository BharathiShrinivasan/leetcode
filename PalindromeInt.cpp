#include<stdio.h>
#include<cstdlib>

bool isPalindrome(int x){

	if(x<0) return false;
	else{
	    int firstHalf=0,secoundHalf=0,tempX=x;
	    int noOfDigits=0;
	    for(noOfDigits=0;tempX>0;tempX/=10,noOfDigits++);
	    printf("noOfDigits- %d\n",noOfDigits);
	
	    tempX=x;
	    for(int i=0;i<noOfDigits/2;i++){
	        firstHalf=firstHalf*10+tempX%10;
	        tempX/=10;
	    }
	    printf("firstHalf- %d\n",firstHalf);
	
	    if(noOfDigits%2==1){ // 5digit, 7digit
	            tempX/=10;
	            printf("tempX- %d\n",tempX);
	            return tempX==firstHalf;
	    }
	    else{
	    	printf("tempX- %d\n",tempX);
	    	return tempX==firstHalf;
		}
	}
}

bool isPalindromeOld(int x){

if(x<0) return false;
else{

    int reversedInt=0,tempX=x;
    while(tempX>0){
        reversedInt=reversedInt*10 + tempX%10;
        tempX=tempX/10;
    }
    return reversedInt==x;

}
}

bool isPalindromeLeetCode1(int num) {
  if (num < 0 || (num % 10 == 0 && num != 0)) {
    /* Negative numbers and numbers ending with 0 are not palindromes */
    return false;
  }

  int reverse = 0;
  while (num > reverse) {
    reverse = reverse * 10 + num % 10;
    num /= 10;
  }

  return num == reverse || num == reverse / 10;
}

int main()
{
	//isPalindrome(1248118421);
	printf("%d",isPalindromeLeetCode1(1248118421));
	return 1;
}
