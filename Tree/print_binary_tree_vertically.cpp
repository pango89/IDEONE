// C++ PROGRAM FOR PRINTING VERTICAL ORDER OF A GIVEN BINARY TREE
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
// STRUCTURE FOR A BINARY TREE NODE
struct Node
{
    int key;
    Node *left, *right;
};
 
// A UTILITY FUNCTION TO CREATE A NEW NODE
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
 
// UTILITY FUNCTION TO STORE VERTICAL ORDER IN MAP 'M'
// 'HD' IS HORIGONTAL DISTANCE OF CURRENT NODE FROM ROOT.
// 'HD' IS INITALLY PASSED AS 0
void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m)
{
    // BASE CASE
    if (root == NULL)
        return;
 
    // STORE CURRENT NODE IN MAP 'M'
    m[hd].push_back(root->key);
 
    // STORE NODES IN LEFT SUBTREE
    getVerticalOrder(root->left, hd-1, m);
 
    // STORE NODES IN RIGHT SUBTREE
    getVerticalOrder(root->right, hd+1, m);
}
 
// THE MAIN FUNCTION TO PRINT VERTICAL ODER OF A BINARY TREE
// WITH GIVEN ROOT
void printVerticalOrder(Node* root)
{
    // CREATE A MAP AND STORE VERTICAL ODER IN MAP USING
    // FUNCTION GETVERTICALORDER()
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd,m);
 
    // TRAVERSE THE MAP AND PRINT NODES AT EVERY HORIGONTAL
    // DISTANCE (HD)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
 
// DRIVER PROGRAM TO TEST ABOVE FUNCTIONS
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
