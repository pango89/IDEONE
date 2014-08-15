#include<iostream>
using namespace std;

string reverse(string str)
{
	if(str.length()==1)
		return str;
	char first=str.at(0);
	string rev_rem=reverse(str.substr(1));
	return rev_rem + first;
}

int main()
{
	string str="Hi All! This is Pankaj Goyal";
	cout<<reverse(str);
	return 0;
}