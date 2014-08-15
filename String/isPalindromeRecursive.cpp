#include<iostream>

using namespace std;
bool isPalindromeUtil(char* start, char* end)
{
	if(start==end)
		return true;
	if(start+1==end)
	{
		if(*start==*end)
			return true;
		else
			return false;
	}
	return isPalindromeUtil(start+1,end-1);
}

bool isPalindrome(char str[])
{
	char* end=str;
	while(*end)
		end++;
	end--;
	isPalindromeUtil(str,end);
}

int main()
{
	char str[]="geeksforrofskeeg";
	if(isPalindrome(str))
		cout<<"YES IT IS PALINDROME"<<endl;
	else
		cout<<"NO IT IS NOT A PALINDROME"<<endl;
	return 0;
}