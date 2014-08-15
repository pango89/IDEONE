#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
bool isFoldableUtil(node* n1,node* n2)
{
	if(n1==NULL && n2==NULL)
		return true;
	if(n1==NULL||n2==NULL)
		return false;
	return (isFoldableUtil(n1->left,n2->right) && isFoldableUtil(n1->right,n2->left));
}
	
bool isFoldable(node* root)
{
	if(root==NULL)
		return true;
	return isFoldableUtil(root->left,root->right);
}

node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

int main()
{
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    root->right->right = newNode(37);
    node *head = NULL;
    if(isFoldable(root) == true)
		printf("\n tree is foldable");
	else
		printf("\n tree is not foldable"); 
    return 0;
}
