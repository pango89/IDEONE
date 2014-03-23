//1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
//Go to right subtree and return the node with minimum key value in right subtree.
//2) If right sbtree of node is NULL, then start from root and us search like technique. Do following.
//Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side.
struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return minValue(n->right);
 
    struct node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}
