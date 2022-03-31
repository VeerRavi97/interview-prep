/*
problem

1. Naive appoach
2. Precompute Height
3. Post Order
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Utility
{
public:
    int getHeight(Node *root)
    {
        if (!root)
            return 0;
        int lh = getHeight(root->left); // 1 2 3
        if (lh == -1)
            return -1;
        int rh = getHeight(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }
};

class Solution
{
public:
    bool isHeightBalanced(Node *root)
    {
        Utility utility;
        int height = utility.getHeight(root);
        return ((height == -1) ? false : true);
    }
};

int main()
{
    Node *root;
/*
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    // root->right->right->right->right = new Node(7);
    */

    // Create Tree

    /*
               1
            2     3
          4         5
                     6
                      

    */

    Solution solution;
    bool res = solution.isHeightBalanced(root);
    if (res)
        cout << "Is Height Balanced" << endl;
    else
        cout << "Not Height Balanced" << endl;

    return 0;
}
