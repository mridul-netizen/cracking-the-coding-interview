//implement a function to check if a binary tree is balanced .For the purposes of this question,
//a balanced tree is defined to be such a tree that the heights of two subtrees of any node
//never differ by more than one
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
};

//returns height of a binary tree
int height(Node *node);

//returns true if binary tree with root as root is height-balanced
bool isBalanced(Node *root)
{
    int lh;//left subtree height
    int rh;//right subtree height

    //if tree is empty then return true
    if(root == NULL)
        return 1;
    //get the height of left,right subtrees
    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    //if we reach here then tree is not balanced
    return 0;
}

//returns maximum of two integers
int max(int a, int b)
{
    return (a >= b)?a:b;
}

//the function computes height of a tree
int height(Node *node)
{
    if(node == NULL)
        return 0;

    //if tree is not empty then height=1+max(left height,right height)
    return 1+max(height(node->left), height(node->right));
}

//Helper function that allocates a new node with given 
//to left and right pointers respectively
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return (node);
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->left->left = newNode(8);

    if(isBalanced(root))
        cout<<"Tree is Balanced";
    else
        cout<<"Tree is not Balanced";
    return 0;
}