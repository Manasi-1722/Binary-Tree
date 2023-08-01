#include <bits/stdc++.h>
using namespace std;


// Search In BT ===== TC - O(n)
// Search In BST ==== TC - O(log n)


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

Node* searchInBst(Node* root, int key)
{
    // base condition 
    if(root == NULL) { 
        return NULL; 
    }

    // check for the given value
    if(root->data == key)
    {
        return root;
    }

    // data < key
    if(root->data > key){
        return searchInBst(root->left, key);
    }

    // data > key
    return searchInBst(root->right, key);
}

// Driver code to test above function
int main()
{
    // Create a binary search Tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    /*
        Binary Search tree
                4
               / \
              2   5   
             / \   \   
            1   3   6
        
    */

    if(searchInBst(root, 15) == NULL)
    {
        cout << "Key doesn't exist" << endl;
    }
    else 
    {
        cout << "Key exist" << endl;
    }


    return 0;
}