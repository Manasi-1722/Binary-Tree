#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* sortedArrayToBST(int arr[], int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void preorder(Node* root)
{
    if(root == NULL){ return; }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int start = 0, end = 4;
    // create a binary search tree from the given array using recursion.
    Node* root = sortedArrayToBST(arr, start, end);
    preorder(root);
    cout << endl;

    return 0;
}