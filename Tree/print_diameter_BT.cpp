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
int max(int a, int b)
{
  return (a >= b)? a: b;
}
int diameterUtil(struct node *root, int* height)
{
  int lh = 0, rh = 0;    
  int ldiameter = 0, rdiameter = 0;  
  if(root == NULL)
  {
    *height = 0;
     return 0; /* diameter is also 0 */
  }  
  ldiameter = diameterUtil(root->left, &lh);
  rdiameter = diameterUtil(root->right, &rh);  
  *height = max(lh, rh) + 1;  
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int diameter(struct node* root)
{
	int height=0;
	return diameterUtil(root,&height);
}
int main()
{ 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  getchar();
  return 0;
}
