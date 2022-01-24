#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform inorder traversal on a given binary tree
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

// A recursive function to construct a full binary tree from the given preorder
// and postorder sequence
Node *buildTree(vector<int> &preorder, int &pIndex, int start, int end, unordered_map<int, int> &map)
{
    // Consider the next item from the given preorder sequence.
    // This item would be the root node of the subtree formed by
    // the postorder[start, end]

    if (start > end)
        return NULL;
    int num = preorder[pIndex++];
    Node *nn = new Node(num);
    if (start == end)
        return nn;
    int next_num = preorder[pIndex];
    int pos = map[next_num];

    nn->left = buildTree(preorder, pIndex, start, pos, map);
    nn->right = buildTree(preorder, pIndex, pos + 1, end - 1, map);

    return nn;
}

// Construct a full binary tree from preorder and postorder sequence
Node *buildTree(vector<int> &preorder, vector<int> &postorder)
{
    // base case
    if (postorder.size() == 0)
    {
        return nullptr;
    }

    // map is used to efficiently find the index of any element in the given
    // postorder sequence
    unordered_map<int, int> map;
    for (int i = 0; i < postorder.size(); i++)
    {
        map[postorder[i]] = i;
    }

    // `pIndex` stores the index of the next node in the preorder sequence
    int pIndex = 0;

    // set range [start, end] for subtree formed by postorder sequence
    int start = 0;
    int end = preorder.size() - 1;

    // construct the binary tree and return it
    return buildTree(preorder, pIndex, start, end, map);
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    vector<int> postorder = {4, 5, 2, 8, 9, 6, 7, 3, 1};

    Node *root = buildTree(preorder, postorder);

    cout << "Inorder traversal is ";
    inorder(root);

    return 0;
}