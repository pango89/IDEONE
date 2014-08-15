//Huffman encoding using priority queue
//http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
 
#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;
#define SENTINAL '\0'
struct node
{
	char character;
	int freq;
	struct node *left;
	struct node *right;
	node(char chas, int fr)
	{
		character= chas; 
		freq=fr;
		left=NULL; 
		right = NULL;
	}; 
};
 
typedef node node;

class nodeCompare 
{
	public:
    bool operator() (node *a, node *b) 
    {
		return (a->freq > b->freq);	
    }
};
//print heap and codes
void print_heap(node *head, string path)
{
	if(!head)
	return;
 
	if(head->character !=SENTINAL)
		cout<< head->character << " code is " << path<<"\n";
 
	print_heap(head->left, path+"0");
	print_heap(head->right, path+"1");
}
 
int main() 
{
	//new queue
	priority_queue<node *, vector<node *>, nodeCompare> minHeap;
 
	//fill queue
	minHeap.push(new node('a',5));
	minHeap.push(new node('b',9));
	minHeap.push(new node('c',12));
	minHeap.push(new node('d',13));
	minHeap.push(new node('e',16));
	minHeap.push(new node('f',45));
 
	//iterate till heapsie is 1
	while(minHeap.size()>1)
	{
		//remove 1
		node *min1= minHeap.top();
		minHeap.pop();
		//remove 2
		node *min2= minHeap.top();
		minHeap.pop();
		//merge both
		node * new_node= new node(SENTINAL, min1->freq + min2->freq);
		new_node->left= min1;
		new_node->right= min2;
		//push back in minHeap
		minHeap.push(new_node);
	}
	print_heap(minHeap.top(), string(""));
	return 0;
}