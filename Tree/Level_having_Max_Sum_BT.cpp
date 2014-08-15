#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return(node);
}

//Function to return the level with max sum
int FindLevelWithMaxSum(struct node* root)
{   node *temp;
    int level=0, maxLevel=0;
    queue<node *> Q;
    int currentSum=0, maxSum=0;
    if(!root)
        return 0;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {   temp=Q.front();
        Q.pop();
        if(temp==NULL)
        {   if(currentSum>maxSum)
            {   maxSum=currentSum;
                maxLevel=level;
            }
            currentSum=0;
            if(!Q.empty())
                Q.push(NULL);
            level++;
        }
        else
        {   currentSum+=temp->data;
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
    return maxLevel;
}
/* Driver program to test*/
int main()
{
	struct node *root1 = newNode(1);    
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left  = newNode(4);
	root1->left->right = newNode(5);   
	
	printf("%d",FindLevelWithMaxSum(root1));
	
	return 0;
}
