#include<iostream>
#include<algorithm>
using namespace std;

bool isPermutation(string str1,string str2)
{
	if(str1.length()!=str2.length())
		return false;
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	return str1==str2;
}

int main()
{
	if(isPermutation("ematter","ermatte"))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}