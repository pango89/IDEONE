#include<iostream>
#include<stack>
using namespace std;
void reverse(char str[])
{
	stack<char> s1;
	int i=0;
	for(;str[i];i++)
		s1.push(str[i]);
	i=0;
	while(!s1.empty())	
	{
		str[i++]=s1.top();
		s1.pop();
	}
}
// Driver program to test above functions
int main()
{
    char str[] = "GeeksQuiz";
 
    reverse(str);
    printf("Reversed string is %s", str);
 
    return 0;
}