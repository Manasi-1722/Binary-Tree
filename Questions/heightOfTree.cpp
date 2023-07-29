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

// TC = O(n)   where n is the no. of nodes in binary tree
int calcHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight , rHeight) + 1;
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
    root->right->right->left = new Node(8);


    cout << calcHeight(root) << endl;

    return 0;
}