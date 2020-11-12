//Given a sorted(increasing order)array with unique integer elements,write an algorihtm to create
//a binary search tree with minimal height
//https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
// 1) Get the Middle of the array and make it root.
// 2) Recursively do same for left half and right half.
//       a) Get the middle of left half and make it left child of the root
//           created in step 1.
//       b) Get the middle of right half and make it right child of the
//           root created in step 1.
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//A binary tree node
class TNode {
    public:
        int data;
        TNode *left;
        TNode *right;
};

TNode *newNode(int data);//ye line smjh ni aayi

//a fucntion that constructs a balanced binary search tree from sorted array
TNode *sortedArrayToBST(int arr[], int start, int end) {
    //Base Case
    if(start > end) {
        return NULL;
    }

    //Getv the middle element and make it root
    int mid = (start+end)/2;
    TNode *root = newNode(arr[mid]);

    //recursively construct the left subtree and make it 
    //left child of the root
    root->left = sortedArrayToBST(arr, start, mid-1);

    //recursively construct the right subtree and
    // make it right child of the root
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;
}

//Helper function that allocates a new node with the given data and NULL
//left and right pointers
TNode *newNode(int data) {
    TNode *node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrder(TNode *node) {
    if(node == NULL) {
        return ;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    //convert list to bst
    TNode *root = sortedArrayToBST(arr, 0, n-1);//0 is for the starting node
    cout<<"PreOrder Traversal of constructed BST \n";
    preOrder(root);

    return 0;
}