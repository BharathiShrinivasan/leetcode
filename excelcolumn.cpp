#include<stdio.h>
#include<cstdlib>
#include<string.h>

char * convertToTitle(int columnNumber){
	char *result=(char *) malloc(sizeof(char));
	result[0]='\0';
	int size=1;
	while(columnNumber>0){
		result=(char*)realloc(result,++size);
		for(int i=size-1;i>0;i--)
		result[i]=result[i-1];
		int residue=(columnNumber-1)%26;
		result[0]=residue+'A';
		columnNumber=(columnNumber-(residue+1))/26;
	}
    return result;
}

char* convertToTitle_efficient(int columnNumber) {
    char str[] = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
    char* ans = (char*)malloc(100 * sizeof(char));
    int i = 0;

    while (columnNumber > 0) {
        ans[i] = str[columnNumber % 26];
        if (ans[i] == 'Z')
            columnNumber--;
        columnNumber /= 26;
        i++;
    }

    ans[i] = '\0';
    int len = strlen(ans);
    for (int j = 0; j < len / 2; j++) {
        char temp = ans[j];
        ans[j] = ans[len - j - 1];
        ans[len - j - 1] = temp;
    }
    return ans;
}

int main(){
	int x=701;//701;
	//char *ptr=convertToTitle(x);
	char *ptr=convertToTitle_efficient(x);
	printf("%s",ptr);
	return 1;
}

/*
	//funct(96);
	printf("%c",(x%26)+'A');
	x=x/26;
	while(x>0){
		printf("%c",((x-1)%26)+'A');
		x=x/26;
	}
*/
