#include<stdio.h>
#include<cstdlib>

char * longestPalindrome(char * s){
	
	

    char* longestPali=(char *)malloc(1000*sizeof(char));

    longestPali[0]=s[0]; longestPali[1]='\0';

    unsigned int longestPaliLength=1;

    for(int i=1;s[i+longestPaliLength]!='\0';i++)
    {
        int leftIndex=i, rightIndex=i;
        int CurrentPaliLength=0;
        if(s[i]!=s[i+1]){
            // odd pali
            leftIndex=i; rightIndex=i;
        }
        else{
            // even pali
            leftIndex=i; rightIndex=i+1;
            CurrentPaliLength++;
        }
        int j=0;
        for(j=0;s[rightIndex+j]!='\0' && (leftIndex-j)>=0;j++)
        {
            if(s[rightIndex+j]==s[leftIndex-j]){
                CurrentPaliLength++;
            }
            else{
                break;
            }        
        }

        if(CurrentPaliLength>longestPaliLength){
            longestPaliLength=CurrentPaliLength; // update new long length
            int l=0;
            for(int k=leftIndex-(j-1);k<=rightIndex+(j-1);k++,l++) longestPali[l]=s[k];
            longestPali[l]='\0';
        }
    }

    return longestPali;
}

char * longestPali1(char *s){
	
	int size=0; for(;s[size++]!='\0';);
	
	char *result=(char*)malloc(sizeof(char)*size);
	int longestLength=1;
	result[0]=s[0];result[1]='\0';
	
	for(int leftIndex=0;leftIndex<size+longestLength;leftIndex++)
	{	
		int length=0;
		for(int rightIndex=size-1;rightIndex>leftIndex;rightIndex--){
			
			printf("%d,%d\n",leftIndex,rightIndex);
			if(s[rightIndex]==s[leftIndex]){
				printf(".");
				length=rightIndex-leftIndex+1;
				if(length>longestLength){
					printf("*");
					bool isPal=true;
					for(int j=leftIndex,i=rightIndex;j<i;i--,j++){
						if(s[j]!=s[i]){
							isPal=false; break;
						}
					}
					
					if(isPal==true){
						printf("/");
						longestLength=length;
			            int l=0;
			            for(int k=leftIndex;k<=rightIndex;k++) result[l++]=s[k];
			            result[l]='\0';
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	char data[]="a";//"Helwwwleemeeo";
	char *ptr;

	//ptr=longestPalindrome(data);
	ptr=longestPali1(data);
	
	printf("pal- %s",ptr);
	
	free(ptr);
		
	return 0;
}
