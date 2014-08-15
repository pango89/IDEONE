#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void iterativePostorder(node *root)
{
    if (root == NULL)
       return;
    stack<node *> nodeStack1;
    stack<node *> nodeStack2;
    nodeStack1.push(root);
    struct node *node=NULL;    
    while (nodeStack1.empty() == false)
    {
        node = nodeStack1.top();
        nodeStack1.pop();
		nodeStack2.push(node);
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
int main()
{
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
