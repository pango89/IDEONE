#include<iostream>

using namespace std;

int countCompression(string str)
{
	int strlength=str.length();
	if(strlength==0)
		return 0;
	int size=0;
	char last=str.at(0);
	int count=1;
	for(int i=1;i<strlength;i++)
	{
		if(last==str.at(i))
		{
			count++;
		}
		else
		{
			size+=1+(to_string(count)).length();
			count=1;
			last=str.at(i);
		}
	}
	size+=1+(to_string(count)).length();
	return size;
}

int setChar(char arr[],int index, char ch, int count)
{
	arr[index]=ch;
	index++;
	string cnt=to_string(count);
	for(int i=0;i<cnt.length();i++)
	{
		arr[index]=cnt[i];
		index++;
	}
	return index;
}

string compressString(string str)
{
	int size=countCompression(str);
	//cout<<size<<endl;
	if(size>=str.length())
		return str;
	
	char* arr=new char[size];
	char last=str.at(0);
	int count=1;
	int index=0;
	
	for(int i=1;i<str.length();i++)
	{
		if(str.at(i)==last)
		{
			count++;
		}
		else
		{
			index=setChar(arr,index,last,count);
			last=str.at(i);
			count=1;
		}
	}
	index=setChar(arr,index,last,count);
	return string(arr);
}

int main()
{
	string str="abbbbbbccccccddddddeeeeeeeefg";
	cout<<compressString(str);
	return 0;
}
