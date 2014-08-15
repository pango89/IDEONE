#include<iostream>
#include<queue>
using namespace std;

/* STRUCTURE OF STACK HAVING TWO QUEUES */
struct _stack
{
	queue<int> q1;
	queue<int> q2;
};

/* FUNCTION TO push AN ITEM TO stack */
void push(_stack* s1, int x)
{
	s1->q1.push(x);
}

/* FUNCTION TO pop AN ITEM FROM stack */
int pop(_stack* s1)
{
	int ele=0;
	if(s1->q1.empty())
		return -1;
	while((s1->q1.size()) > 1)
	{
		s1->q2.push(s1->q1.front());
		s1->q1.pop();
	}
	ele=s1->q1.front();
	s1->q1.pop();
	//SWAP Q1 AND Q2
	queue<int> temp=s1->q1;
	s1->q1=s1->q2;
	s1->q2=temp;
	
	return ele;
}

/* DRIVER FUNCTION TO TEST ANOVE FUNCTIONS */
int main()
{
   /* CREATE A stack WITH ITEMS 1 2 3*/
   _stack *s = new _stack;
   push(s, 1);
   push(s, 2);
   push(s, 3);    
  
   /* popped ITEMS */
   printf("%d  ", pop(s));
   printf("%d  ", pop(s));
   printf("%d  ", pop(s));  
  
   return 0;
}
