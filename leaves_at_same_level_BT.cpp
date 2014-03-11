#include<iostream>
#include<cstdio>
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
int checkUtil(node* root,int level)
{
	if(root==NULL)
		return 1;
	if(root->left==NULL && root->right==NULL)
		return level;
	return (checkUtil(root->left,level+1)==checkUtil(root->right,level+1));
}

bool check(node* root)
{
	//let root is at level 1
	int level=1;
	return checkUtil(root,level);
}	

int main()
{
	node *root = newNode(12);
    root->left = newNode(5);
    //root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    return 0;
}
