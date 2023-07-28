#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

// using inoder and preorder
Node* build_tree(int inorder[], int preorder[], int start, int end)
{
    static int id = 0;
    if(start > end)
    {
        return NULL;
    }
    
    int curr = preorder[id];
    id++;
    Node* node = new Node(curr);

    if(start == end)
    {
        return node;
    }
    
    int pos = search(inorder, start, end, curr);
    node->left = build_tree(inorder, preorder, start, pos - 1);
    node->right = build_tree(inorder, preorder, pos + 1, end);
    
    return node;
    
}

void inorderprint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->val << " ";
    inorderprint(root->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    
    Node* root = build_tree(inorder, preorder, 0, 4);
    inorderprint(root);

    return 0;
}