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

int minValue(Node* root)
{
    int mini = root->data;
    while(root->left != NULL)
    {
        mini = root->left->data;
        root = root->left;
    }
    return mini;
}

Node* deleteBST(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(key < root->data) {
        root->left = deleteBST(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteBST(root->right, key);
    }

    else {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        
        root->data = minValue(root->right);
        root->right = deleteBST(root->right, root->data);
    }
    return root;
}


void inorder(Node* root)
{
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// Driver code to test above function
int main()
{
    // Create a binary search Tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    /*
        Binary Search tree
                4
               / \
              2   5   
             / \   \   
            1   3   6
        
    */

    inorder(root);
    cout << endl;
    deleteBST(root, 6);
    inorder(root);
    cout << endl;

    return 0;
}

