#include<iostream>

using namespace std;

void replaceSpaces(char str[],int len)
{
	int spacecount=0,newlen=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
			spacecount++;
	}
	newlen=len+spacecount*2;
	str[newlen]='\0';
	for(int i=len-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[newlen-1]='0';
			str[newlen-2]='2';
			str[newlen-3]='%';
			newlen=newlen-3;
		}
		else
		{
			str[newlen-1]=str[i];
			newlen=newlen-1;
		}
	}
}

int main()
{
	char str[]="My home is in Jharkhand";
	int length=strlen(str);
	cout<<string(str)<<endl;
	replaceSpaces(str,length);
	cout<<string(str)<<endl;
	return 0;
}