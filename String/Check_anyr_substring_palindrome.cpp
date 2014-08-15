#include <iostream>
#include <string>
#include <stack>
#include <assert.h>

using namespace std;

bool isPalindrome(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); ++i)
	{
		char currentCharacter = str.at(i);
		if (!s.empty())
		{
			char topCharacter = s.top();
			if (currentCharacter == topCharacter)
				return true;
			if (s.size() > 1)
			{
			    s.pop();
			    char secondOnTop = s.top();
                if (currentCharacter == secondOnTop)
                    return true;
                else
                    s.push(topCharacter);
			}
		}
		s.push(currentCharacter);
	}
	return false;
}

int main()
{
	string testString1 = "aac";
	string testString2 = "madam";
	string testString3 = "abcc";
	string testString4 = "not";
	string testString5 = "abcdefghijklmnopqrstuvwxyz";
	// test the different words
	cout<<(isPalindrome(testString1) == true);
	//assert(isPalindrome(testString2) == true);
	//assert(isPalindrome(testString3) == true);
	//assert(isPalindrome(testString4) == false);
	//assert(isPalindrome(testString5) == false);
	return 0;
}