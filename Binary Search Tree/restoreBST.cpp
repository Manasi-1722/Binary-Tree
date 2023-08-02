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

void helper(Node *root, Node** first, Node** last,Node** mid,Node** prev)
{
    if(root == NULL)
    {
        return;
    }
    helper(root->left, first, last, mid, prev);

    if(*prev != NULL && (root->data < (*prev)->data))
    {
        if(*first == NULL)
        {
            *first = *prev;
            *mid = root;
        }
        else 
            *last = root;
    }
    *prev = root;
    helper(root->right, first, last, mid, prev);
}

void restoreBST(Node* root)
{
    Node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;
    helper(root, &first, &last, &mid, &prev);

    if(first && last)
    {
        swap(first->data, last->data);
    }
    else if(first && mid)
    {
        swap(first->data, mid->data);
    }
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right=new Node(13);

    inorder(root);  // 1 9 4 6 3 13   wrong order
    cout << endl;  

    restoreBST(root);

    inorder(root);  // 1 3 4 6 9 13   right order
    cout << endl;
    return 0;
}