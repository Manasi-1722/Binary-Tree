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

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)    // base condition
    {
        return true;
    }

    else if(root1 == NULL || root2 == NULL)   // structurally not identical
    {
        return false;
    }

    else {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3) {
            return true;
        } else {
            return false;
        }
    }

}
int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    if(isIdentical(root1,root1))
    {
        cout << "Identical BST" << endl;
    }
    else 
    {
        cout << "Not Identical BST" << endl;
    }

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if(isIdentical(root1,root2))
    {
        cout << "Identical BST" << endl;
    }
    else 
    {
        cout << "Not Identical BST" << endl;
    }

    return 0;
}