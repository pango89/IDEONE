#include<iostream>
#include<cstdio>
#include<climits>
#include<stack>

using namespace std;

struct AdvancedStack
{
	stack<int> eleStack;
	stack<int> minStack;
};

void push(AdvancedStack* s1, int x)
{
	s1->eleStack.push(x);
	int top=(s1->minStack.empty())?(INT_MAX):(s1->minStack.top());
	if(s1->eleStack.empty()||(top>=x))//'=' for handling duplicate elements entries
			s1->minStack.push(x);
}

int pop(AdvancedStack* s1)
{
	if(s1->eleStack.empty())
		return -1;
	int ele=s1->eleStack.top();
	s1->eleStack.pop();
	if(ele==s1->minStack.top())
		s1->minStack.pop();
	return ele;
}

int findMin(AdvancedStack* s1)
{
	return s1->minStack.top();
}

/* Driver program to test SpecialStack methods */
int main()
{
    AdvancedStack* s=new AdvancedStack;
    push(s,10);
    push(s,20);
    push(s,30);
    cout<<findMin(s)<<endl;
    push(s,5);
    cout<<findMin(s)<<endl;
    pop(s);
    cout<<findMin(s)<<endl;
    push(s,3);
    cout<<findMin(s)<<endl;
    return 0;
}
