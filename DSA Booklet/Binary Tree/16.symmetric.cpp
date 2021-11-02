#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node *BuildTree(vector<int> &v, int &index)
{
    if (index == v.size())
        return nullptr;
    int curr_ele = v[index++];
    if (curr_ele == -1)
        return nullptr;
    Node *newNode = new Node(curr_ele);
    newNode->left = BuildTree(v, index);
    newNode->right = BuildTree(v, index);
    return newNode;
}

void display(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

void display(Node *root, vector<int> &v)
{
    if (!root)
    {
        v.push_back(-1);
        return;
    }
    cout << root->data << " ";
    v.push_back(root->data);
    display(root->left, v);
    display(root->right, v);
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isMirror(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    bool op1 = (root1->data == root2->data);
    bool op2 = isMirror(root1->left, root2->right);
    bool op3 = isMirror(root1->right, root2->left);
    return (op1 && op2 && op3);
}

bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

bool helper(Node *root1, Node *root2)
{
}

Node *invert(Node *root)
{
    if (!root)
        return nullptr;
    invert(root->left);
    invert(root->right);
    swap(root->left, root->right);
    return root;
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        Node *root = nullptr;
        int n;
        cin >> n;
        vi v(3 * n, 0);
        for (int i = 0; i < 2 * n + 1; i++)
            cin >> v[i];
        int start_idx = 0;
        root = BuildTree(v, start_idx);
        vi sv;
        display(root, sv);
        cout << endl;
        cout << isSymmetric(root) << endl;
        root = invert(root);
        display(root);
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 15
// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1