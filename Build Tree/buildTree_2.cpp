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
Node* build_tree(int inorder[], int postorder[], int start, int end)
{
    static int id = end;
    if(start > end)
    {
        return NULL;
    }
    
    int curr = postorder[id];
    id--;
    Node* node = new Node(curr);

    if(start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->right = build_tree(inorder, postorder, pos + 1, end);
    node->left = build_tree(inorder, postorder, start, pos - 1);
    
    
    return node;
    
}

void inorderPrint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main()
{
    int postorder[] = {4, 2, 1, 5, 3};
    int inorder[] = {4, 2, 1, 5, 3};
    
    Node* root = build_tree(inorder, postorder, 0, 4);
    inorderPrint(root);

    return 0;
}