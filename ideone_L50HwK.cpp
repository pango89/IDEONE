#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
	int val;
	struct node *left,*right;
};
node *newnode(int data)
{
	node *temp=new node;
	temp->val=data;
	temp->left=temp->right=NULL;
	return temp;
}
void deepestleftleafutill(node *root,int lvl,int *maxlvl,bool isleft,node **resptr)
{
	if(root==NULL)
		return;
	if(isleft && (root->left==NULL) && (root->right==NULL) && lvl>*maxlvl)
	{
		*maxlvl=lvl;
		*resptr=root;
		return;
	}
	deepestleftleafutill(root->left,lvl+1,maxlvl,true,resptr);
	deepestleftleafutill(root->right,lvl+1,maxlvl,false,resptr);
}
node *deepestleftleaf(node *root)
{
	int maxlvl=0;
	node *result=NULL;
	deepestleftleafutill(root,0,&maxlvl,false,&result);
	return result;
}
int main()
{
    node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->right->left = newnode(5);
    root->right->right = newnode(6);
    root->right->left->right = newnode(7);
    root->right->right->right = newnode(8);
    //root->right->left->right->left = newnode(9);
    root->right->right->right->right = newnode(10);
 
    node *result = deepestleftleaf(root);
    if (result)
        cout << "The deepest left child is " << result->val;
    else
        cout << "There is no left leaf in the given tree"; 
    return 0;
}