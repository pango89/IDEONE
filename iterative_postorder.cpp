#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePostorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;

    // Create an empty stack and push root to it
    stack<node *> nodeStack1;
	stack<node *> nodeStack2;
    nodeStack1.push(root);
	struct node *node=NULL;
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack1.empty() == false)
    {
        // Pop the top item from stack and print it
        node = nodeStack1.top();
        nodeStack1.pop();
		nodeStack2.push(node);
        // Push right and left children of the popped node to stack
		if (node->left)
            nodeStack1.push(node->left);
        if (node->right)
            nodeStack1.push(node->right);
    }
	 while (nodeStack2.empty() == false)
    {
		node = nodeStack2.top();
        nodeStack2.pop();
		printf("%d ",node->data);
	}
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  iterativePostorder(root);
  return 0;
}
