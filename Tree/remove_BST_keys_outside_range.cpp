// A C++ program to remove BST datas outside the given range
#include<iostream>
using namespace std;
// A BST node has data, and left and right pointers
struct node
{
	int data;
	node* left;
	node* right;
};
// A utility function to create a new BST node with data as given num
node* newNode(int data)
{
	node* temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
// A utility function to insert a given data to BST
node* insert(node* root, int data)
{
    if (root == NULL)
       return newNode(data);
    if (root->data > data)
       root->left = insert(root->left, data);
    else
       root->right = insert(root->right, data);
    return root;
}
// Utility function to traverse the binary tree after conversion
void inorder(node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		inorder(root->left);
		inorder(root->right);
	}
}
// Removes all nodes having value outside the given range and returns the root
// of modified tree
node* removeOutsideRange(node* root,int min,int max)
{
	if(root==NULL)
		return NULL;
	root->left=removeOutsideRange(root->left,min,max);
	root->right=removeOutsideRange(root->right,min,max);
	if(root->data<min)
	{
		node* temp=root->right;
		delete root;
		return temp;
	}
	if(root->data>max)
	{
		node* temp=root->left;
		delete root;
		return temp;
	}
	return root;
} 
// Driver program to test above functions
int main()
{
    node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7); 
    cout << "Inorder traversal of the given tree is: ";
    inorder(root); 
    root = removeOutsideRange(root, -10, 12); 
    cout << "\nInorder traversal of the modified tree is: ";
    inorder(root); 
    return 0;
}
