#include<stdio.h>
#include<malloc.h>
//A Binary Tree Node
struct node
{
	int data;
	struct node *left, *right;
};
// A utility function to allocate a new tree node
struct node *newNode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void printNmaxUtil(struct node* root,int N,int* count)
{
	
	if(root==NULL)
		return;
	printNmaxUtil(root->right,N,count);
	if((++*count)<=N)
		printf("%d ",root->data);
	printNmaxUtil(root->left,N,count);
}
void printNmax(struct node* root,int N)
{
	int count=0;
	printNmaxUtil(root,N,&count);
}
int main()
{
	//COMMENT ADDED
	struct node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);    
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
	
	printNmax(root,3);
	return 0;
}
