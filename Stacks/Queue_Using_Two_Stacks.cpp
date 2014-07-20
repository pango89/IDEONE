#include<iostream>
#include<stack>
using namespace std;

/* STRUCTURE OF QUEUE HAVING TWO STACKS */
struct _queue
{
	stack<int> s1;
	stack<int> s2;
};

/* FUNCTION TO ENQUEUE AN ITEM TO QUEUE */
void enQueue(_queue* q1, int x)
{
	q1->s1.push(x);
}

/* FUNCTION TO DEQUEUE AN ITEM FROM QUEUE */
int deQueue(_queue* q1)
{
	int ele=0;
	if(q1->s1.empty() && q1->s2.empty())
	{
		printf("Error");
		exit(0);
	}
	if(q1->s2.empty())
	{
		while(!q1->s1.empty())
		{
			int temp=q1->s1.top();
			q1->s1.pop();
			q1->s2.push(temp);
		}
	}
	ele=q1->s2.top();
	q1->s2.pop();
	
	return ele;
}

/* DRIVER FUNCTION TO TEST ANOVE FUNCTIONS */
int main()
{
   /* CREATE A QUEUE WITH ITEMS 1 2 3*/
   _queue *q = new _queue;
   enQueue(q, 1);
   enQueue(q, 2);
   enQueue(q, 3);    
  
   /* DEQUEUE ITEMS */
   printf("%d  ", deQueue(q));
   printf("%d  ", deQueue(q));
   printf("%d  ", deQueue(q));  
  
   return 0;
}