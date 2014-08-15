/*LCA OF A BINARY TREE IF PARENT POINTER IS GIVEN
|-----------------------------------------------------|
|-----------------THE BEST SOLUTION:------------------|
|-----------------------------------------------------|
A LITTLE CREATIVITY IS NEEDED HERE. SINCE WE HAVE THE PARENT POINTER, 
WE COULD EASILY GET THE DISTANCE (HEIGHT) OF BOTH NODES FROM THE ROOT. 
ONCE WE KNEW BOTH HEIGHTS, WE COULD SUBTRACT FROM ONE ANOTHER AND GET 
THE HEIGHT’S DIFFERENCE (DH). IF YOU OBSERVE CAREFULLY FROM THE PREVIOUS 
SOLUTION, THE NODE WHICH IS CLOSER TO THE ROOT IS ALWAYS DH STEPS AHEAD 
OF THE DEEPER NODE. WE COULD ELIMINATE THE NEED OF MARKING VISITED NODES ALTOGETHER. WHY?

THE REASON IS SIMPLE, IF WE ADVANCE THE DEEPER NODE DH STEPS ABOVE, 
BOTH NODES WOULD BE AT THE SAME DEPTH. THEN, WE ADVANCE BOTH NODES 
ONE LEVEL AT A TIME. THEY WOULD THEN EVENTUALLY INTERSECT AT ONE NODE, 
WHICH IS THE LCA OF BOTH NODES. IF NOT, ONE OF THE NODE WOULD EVENTUALLY 
REACH NULL (ROOT’S PARENT), WHICH WE CONCLUDE THAT BOTH NODES ARE NOT IN 
THE SAME TREE. HOWEVER, THAT PART OF CODE SHOULDN’T BE REACHED, SINCE THE 
PROBLEM STATEMENT ASSUMED THAT BOTH NODES ARE IN THE SAME TREE.
*/
#include<cstdio>
#include<limits>
 
/* A tree Node structure */
struct Node
{
    int data;
    Node *left;
    Node *right;
	Node* parent;
};
 
int getHeight(Node *p) 
{
  int height = 0;
  while (p) 
  {
    height++;
    p = p->parent;
  }
  return height;
}
 
// As root->parent is NULL, we don't need to pass root in.
Node *LCA(Node *p, Node *q) 
{
  int h1 = getHeight(p);
  int h2 = getHeight(q);
  // swap both Nodes in case p is deeper than q.
  if (h1 > h2) 
  {
    swap(h1, h2);
    swap(p, q);
  }
  // invariant: h1 <= h2.
  int dh = h2 - h1;
  for (int h = 0; h < dh; h++)
    q = q->parent;
  while (p && q) 
  {
    if (p == q) 
		return p;
    p = p->parent;
    q = q->parent;
  }
  return NULL;  // p and q are not in the same tree
}
 
/* Utility function to create a new Binary Tree node */
Node* newNode (int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Driver function to test above functions */
int main()
{
    Node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("LCA of  \n");
    int sum = LCA(root);
    printf ("\nSum of the nodes is %d ", sum);
 
    getchar();
    return 0;
}