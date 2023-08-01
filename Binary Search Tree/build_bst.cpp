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

Node* insertBST(Node* root, int val)
{
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data)  // left subtree coz lesser
    {
        root->left = insertBST(root->left, val);
    }
    else                 // right subtree coz greater
    {
        root->right = insertBST(root->right, val);
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
int main()
{
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    
    // Inorder traversal of any BST gives sequence in a sorted order. 
    // 1 2 3 4 5 7  - ans
    inorder(root);   
    cout << endl;

    return 0;
}