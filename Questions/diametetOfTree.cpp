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


/*     TC = O(n^2) Not Optimal     */
// int calcHeight(Node* root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }

//     return max(calcHeight(root->left), calcHeight(root->right)) + 1;
// }
// int diameter(Node* root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }
//     int lh = calcHeight(root->left);
//     int rh = calcHeight(root->right);

//     int currH = lh + rh + 1;

//     int ld = diameter(root->left);
//     int rd = diameter(root->right);

//     return max(currH, max(ld, rd));
// }

/*     TC = O(n) ****Optimal*****    */

int diameter(Node* root, int* height)
{
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh , rh = 0;
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);

    int currDiameter = ldiameter + rdiameter + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(ldiameter, rdiameter));
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;
    cout << diameter(root, &height) << endl;

    return 0;
}