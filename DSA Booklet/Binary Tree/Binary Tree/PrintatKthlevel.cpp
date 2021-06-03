#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int node_data)
    {
        this->data = node_data;
        left = right = NULL;
    }
};
class Solution
{
public:
    int height(Node *root)
    {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
    void printAtKthLevel(Node *root, int k)
    {
        if (!root)
            return;
        if (k == 1)
        {
            cout << root->data << " ";
            return;
        }
        printAtKthLevel(root->left, k - 1);
        printAtKthLevel(root->right, k - 1);
    }
    void printAtKthLevelModified(Node *root, int k, int ltr)
    {
        if (!root)
            return;
        if (k == 1)
        {
            cout << root->data << " ";
            return;
        }
        if (ltr)
        {
            printAtKthLevelModified(root->left, k - 1, ltr);
            printAtKthLevelModified(root->right, k - 1, ltr);
            return;
        }
        printAtKthLevelModified(root->right, k - 1, ltr);
        printAtKthLevelModified(root->left, k - 1, ltr);
    }
    void ZigSpiral(Node *root)
    {
        int h = height(root);
        int ltr = 1;
        for (int i = 1; i <= h; i++)
        {
            printAtKthLevelModified(root, i, ltr);
            ltr = !ltr;
            cout << endl;
        }
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);

    Solution MyTree;
    int h = MyTree.height(root);
    //cout << h << endl;
    for (int i = 1; i <= h; i++)
    {
        MyTree.printAtKthLevel(root, i);
        cout << endl;
    }
    MyTree.ZigSpiral(root);

    return 0;
}