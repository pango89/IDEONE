#include<iostream>
#define CHAR_SET_SIZE 256
using namespace std;

bool isPermutation(string str1,string str2)
{
	if(str1.length()!=str2.length())
		return false;
	int arr[CHAR_SET_SIZE]={0};
	for(int i=0;i<str1.length();i++)
	{
		char ch=str1.at(i);
		arr[ch]+=1;
	}
	for(int i=0;i<str2.length();i++)
	{
		char ch=str2.at(i);
		if(--arr[ch]<0)
			return false;
	}
	return true;
}

int main()
{
	if(isPermutation("ematter","ermate"))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}