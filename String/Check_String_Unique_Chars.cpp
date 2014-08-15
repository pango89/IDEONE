#include<iostream>
#define CHAR_SET_SIZE 256
using namespace std;

bool hasUniqueChars(string str)
{
	if(str.length() > CHAR_SET_SIZE)
		return false;
	//bool* arr=new bool[CHAR_SET_SIZE];
	bool arr[CHAR_SET_SIZE]={false};
	for(int i=0;i<str.length();i++)
	{
		char ch=str.at(i);
		if(arr[ch])
			return false;
		arr[ch]=true;
	}
	return true;
}
int main()
{
	string str="HiAL! ThsPankjGoyl";
	if(hasUniqueChars(str))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
	return 0;
}