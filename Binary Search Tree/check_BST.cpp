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

// TC - O(n)
bool isBST(Node* root, Node* min = NULL, Node* max = NULL)
{
    if(root == NULL)
    {
        return true;
    }

    if(min != NULL && min->data >= root->data)
    {
        return false;
    }
    if(max != NULL && max->data <= root->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;

}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    if(isBST(root1, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else 
    {
        cout << "Invalid BSt" << endl;
    }

    Node* root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);

    if(isBST(root2, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else 
    {
        cout << "Invalid BSt" << endl;
    }

    return 0;
}