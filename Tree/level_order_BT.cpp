#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* newNode(int data)
{
	node* temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printLevelOrder(node* root)
{
	
	if(root==NULL)
		return;
	queue<node*> q1;
	q1.push(root);
	while(!q1.empty())
	{
		node* temp=q1.front();
		q1.pop();
		printf("%d ",temp->data);
		if(temp->left!=NULL)
			q1.push(temp->left);
		if(temp->right!=NULL)
			q1.push(temp->right);
	}
}
int main()
{
	node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);  
	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);
	return 0;
}
