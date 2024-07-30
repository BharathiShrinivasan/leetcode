#include<stdio.h>
#include<cstdlib>
#include<string.h>

int lengthOfLongestSubstring(char * s){

    int CurrentLongest=0,LengthCount=0;
    char substring[100]={'\0'};
    bool SkipToNext=false;

    for(int i=0;s[i]!='\0';i++)
    {
        substring[0]=s[i];substring[1]='\0';LengthCount=1;
        /*if(((substring[0]>='a' && substring[0]<='z')||(substring[0]>='A' && substring[0]<='Z'))==false){
        	LengthCount=0;substring[0]='\0'; continue;
		}*/
		
        SkipToNext=false;
        for(int j=i+1;s[j]!='\0' && SkipToNext==false;j++)
        {
            for(int k=0;substring[k]!='\0';k++){
				/*if(((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z'))==false){
				        	if(CurrentLongest<LengthCount)CurrentLongest=LengthCount;
							SkipToNext=true; break;
						}*/
            	if(substring[k]==s[j]) {SkipToNext=true; break;}
			}
            

            if(SkipToNext==false){
                substring[LengthCount++]=s[j];substring[LengthCount]='\0';
            }
            
        }
        if(CurrentLongest<LengthCount)CurrentLongest=LengthCount;
        printf("substring - %s length - %d\n",substring,LengthCount);
    }

    return CurrentLongest;

}

#define max(a,b) a>b?a:b

int OptimalAlgo_lengthOfLongestSubstring(char * s){

	int s_len = strlen(s);
    int max_count = 0;
    int *hash = (int*)calloc(95, sizeof(int));
    int left = 0;
    int right = 0;

    while (right < s_len)
    {
        if (hash[s[right] - 32] == 0)
            hash[s[right++] - 32] = 1;

        else if (hash[s[right] - 32] == 1)
            hash[s[left++] - 32] = 0;

        max_count = max(max_count, right - left);
    }

    free(hash);
    return max_count;

}

int main()
{
	char data[]="cool1";
	//int x = lengthOfLongestSubstring(data);
	int x = OptimalAlgo_lengthOfLongestSubstring(data);
	printf("\nlongest length = %d",x);
	
	return 0;
}
