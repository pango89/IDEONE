#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
void addGreaterUtil(node* root,int* sum_ptr)
{
	if(root==NULL)
		return;
	addGreaterUtil(root->right,sum_ptr);
	*sum_ptr=*sum_ptr + root->data;
	root->data=*sum_ptr;
	addGreaterUtil(root->left,sum_ptr);
}
	
void addGreater(node* root)
{
	if(root==NULL)
		return;
	int sum=0;
	addGreaterUtil(root,&sum);
}

node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int main()
{
    node *root =  newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
    printf(" Inorder traversal of the given tree\n");
    printInorder(root); 
    addGreater(root); 
    printf("\n Inorder traversal of the modified tree\n");
    printInorder(root);
    return 0;
}
