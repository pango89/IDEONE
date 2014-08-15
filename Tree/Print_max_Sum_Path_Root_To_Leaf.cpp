#include<cstdio>
#include<vector>

using namespace std;

struct node
{
   int data;
   struct node* left;
   struct node* right;
};

struct node* newnode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;  
  return(node);
}

int maxSumPathRootToLeafUtil(node* root, vector<int> &list)
{
	if(!root)
		return 0;

	vector<int> rightList, leftList;
	int	rightSum = maxSumPathRootToLeafUtil(root->right, rightList);
	int	leftSum  = maxSumPathRootToLeafUtil(root->left, leftList);

	int result = 0;

	if(rightSum > leftSum)
	{
		list = rightList;
		list.push_back(root->data);
		result = rightSum + root->data;
	}
	else
	{
		list = leftList;
		list.push_back(root->data);
		result = leftSum + root->data;
	}
	return result;
}

void maxSumPathRootToLeaf(node* root)
{
	if(!root)
		return;

	vector<int> list;
	//vector<int>::iterator it;
	
	int sum = maxSumPathRootToLeafUtil(root,list);
	
	cout << "Max Sum from Root to Leaf is " << sum << endl;
	cout << "Max Sum Path from Root to Leaf is ";
	//for(it = list.end(); it != list.begin(); ++it)
		//cout<<*it<<" ";
	//cout<<list.size()<<endl;
	for(int i=list.size()-1;i>=0;i--)
		cout<<list[i]<<" ";
}
int main()
{
	struct node *root = newnode(10);
	root->left        = newnode(8);
	root->right       = newnode(2);
	root->left->left  = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);
	
	maxSumPathRootToLeaf(root);
	
	getchar();
	return 0;
}