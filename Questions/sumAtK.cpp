#include <bits/stdc++.h>
using namespace std;

class Node {
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

int sumAtK(Node* root, int K)
{
    if(root == NULL)\
    {
        return -1;
    }

    queue<Node*> q;
    int level = 0;
    int sum = 0;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            if(level == K)
            {
                sum += node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }   
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    
    }
    return sum;
    
}
int main()
{
    // Create a root node with value as '1' and create two child nodes for it.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << sumAtK(root, 2);
    return 0;
}