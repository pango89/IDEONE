#include<iostream>
#include<cstdio>
using namespace std;

void reverse(char* str)
{
	char *end=str;
	while(*end)
		end++;
	end--;//SET ONE CHAR BACK AS LAST CHAR IS NULL
	while(str<end)
	{
		char temp=*str;
		*str=*end;
		*end=temp;
		str++;
		end--;
	}
}
int main()
{
	char str[]="Boston is a beautiful City";
	printf("Before Reversing:%s\n",str);
	reverse(str);
	printf("After Reversing:%s\n",str);
	return 0;
}