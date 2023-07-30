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

void flatten(Node* root)
{
    if(root->left != NULL)
    {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }
    flatten(root->right);
}
int main()
{

    return 0;
}