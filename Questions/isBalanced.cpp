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

int height(Node* root)
{
    if (root == NULL) 
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

/*  TC - O(n^2)  Not Optimal  */
bool isBalanced(Node* root)
{
    if (root == NULL) // base case for empty tree. If the node does not exist
    {
        return true;
    }

    if(isBalanced(root->left) == false)
    {
        return false;
    }

    if(isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1) 
    {
        return true;
    }
    else{
        return false;
    }
}


bool isBalanced(Node* root, int* height)
{
    if(root == NULL)
    {
        return true;
    }
    int lh , rh = 0;

    if(isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if(isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    // Balanced Tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    // Unbalanced tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    int height = 0;
    if(isBalanced(root2, &height) == true)
    {
        cout << "Balanced Tree" << endl;
    }
    else 
    {
        cout << "Unbalanced Tree" << endl;
    }
    return 0;
}