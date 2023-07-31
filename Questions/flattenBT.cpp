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
            this->left=NULL;
            this->right=NULL;
        }
};

void flatten(Node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if(root->left != NULL)
    {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }
    flatten(root->right);
}

void inorderPrint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    // Traverse left subtree, then print the data of node and finally traverse right sub-tree
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
    
}
int main()
{
/*
        4
      /  \
     9    5
    /\    \
   1  3    6 
*/

    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    flatten(root); 
    inorderPrint(root);
    cout << endl;

    return 0;
}