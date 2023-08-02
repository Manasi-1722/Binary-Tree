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

void zigzagTraversal(Node* root)
{
    if(root == NULL)   // base condition
    {
        return;
    }

    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp)
        {
            cout << temp->data << " ";
            
            // left to right
            if(leftToRight) {
                if(temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }

            // right to left
            else {
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if(temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    zigzagTraversal(root);   // ans - 12 15 9 5 10 
    cout << endl;

    return 0;
}