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

int helper(Node* root, int &ans)
{
    if(root == NULL)
    {
        return 0;
    } 
    // Find the largest of two possible paths from current node to leaf nodes.
    int left = helper(root->left, ans);
    int right = helper(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                  max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);
    int singleNode = max(root->data, max(root->data + left, root->data + right));
    return singleNode;
}

int maxPathSum(Node* root)
{
    int ans = INT_MIN;
    helper(root,ans);
    return ans;
}

int main()
{
/* Constructing tree
        1
       / \
      2   3
     /     \         max sum = 15
    4       5
*/
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->right->right = new Node(5);
   
   cout << maxPathSum(root) << endl;

    return 0;
}