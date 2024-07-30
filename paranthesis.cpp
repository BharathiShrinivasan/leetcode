#include<stdio.h>

bool isValid(char * s){
    int len=0;
    while(s[len]!='\0')len++;

    if(len%2) return false;
    else{
        char stack[len];
        int pointer=0;
        if(s[0]=='('||s[0]=='{'||s[0]=='[')stack[0]=s[0];
        else return false;

        for(int i=1;i<len;i++)
        {
            char notChar='\0';
            if(pointer>=0){
                switch(stack[pointer]){
                    case '(': notChar=')'; break;
                    case '{': notChar='}';break;
                    case '[': notChar=']';break;
                }
                if(s[i]==notChar)pointer--;
                else{
                    if(s[i]=='('||s[i]=='{'||s[i]=='['){
                        stack[++pointer]=s[i];
                    }
                    else return false;
                }
            }
            else{
                if(s[i]=='('||s[i]=='{'||s[i]=='['){
                    stack[++pointer]=s[i];
                }
                else return false;
            }

        }
        if(pointer==-1) return true;
        else false;
    }

    return false;
}

int main(){
	char s[]="()[]{}((}{}())";
	printf("%d",isValid(s));
	return 1;
}
