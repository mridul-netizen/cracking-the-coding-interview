//Implement a function to check if a binary tree is a binary search tree
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left,*right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

bool isBSTUtil(struct Node *root, Node *&prev)//value of prev will be changed from NULL to newly allocate memory 
//that is root maybe
{
    if(root)//check if root != NULL
    {
        if(!isBSTUtil(root->left,prev))
        //repeatedly calling itself till last left subchild and then returning true
            return false;
        //Now freeing up the memory taking away function from the stack
        if(prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }
    return true;
}


bool isBST(Node *root)
{
    Node *prev = NULL;
    return isBSTUtil(root,prev);
}

int main()
{
    struct Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->right->left = new Node(4);

    if(isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";

    return 0;
}