#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void reverse(char* start, char* end)
{
	while(start<end)
	{
		char temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}
void reverseWords(char* str)
{
	char* wbegin=str;
	char* temp=str;
	while(*temp)
	{
		temp++;
		if(*temp=='\0')
		{
			reverse(wbegin,temp-1);
		}
		if(*temp==' ')
		{
			reverse(wbegin,temp-1);
			wbegin=temp+1;
		}
	}
	reverse(str,temp-1);
}
void initcap(char* str)
{
	bool found=false;
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(!found && isalpha(str[i]))
		{
			str[i]=toupper(str[i]);
			found=true;
		}
		else if(str[i]==' ')
		{
			found=false;
		}
	}		
}	
int main()
{
	char str[]="If you do not do as i direct, there will be consequences!";
	printf("Before Reversing:%s\n",str);	
	reverseWords(str);
	printf("After Reversing Words:%s\n",str);
	initcap(str);
	printf("After Capitalizing Initials:%s\n",str);
	return 0;
}