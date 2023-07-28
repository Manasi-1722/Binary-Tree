#include <bits/stdc++.h>
using namespace std;


// SUM of all nodes =  left subtree sum + 
                    // right subtree sum + 
                    // current node value 
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

int sumNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << sumNodes(root) << endl;

    return 0;
}