//ASSUME THAT THE STRING CONTAINS ONLY LOWERCASE LETTERS
//A TOTAL OF 26 CHARACTERS ARE AVAILABLE SO A
//BIT VECTOR OF SIZE 32 CAN BE USED .WE USE ONE INT(32 BITS)

#include<iostream>
using namespace std;

int charToInt(char ch)
{
	return ch - 'a' ;
}

bool hasUniqueChars(string str)
{
	int checker=0;
	for(int i=0;i<str.length();i++)
	{
		int index=charToInt(str.at(i));
		if(checker & (1<<index))
			return false;
		checker = checker | (1<<index);
	}
	return true;
}

int main()
{
	string str="pankjgoyal";
	if(hasUniqueChars(str))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
	return 0;
}