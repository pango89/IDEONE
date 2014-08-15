#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

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
	char str[]="Boston is a beautiful City";
	printf("Before Capitalizing:%s\n",str);
	initcap(str);
	printf("After Capitalizing:%s\n",str);
	return 0;
}