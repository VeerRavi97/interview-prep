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

void flattenI(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
        {
            s.push(curr->left);
            curr->right = curr->left;
        }
        else if (!s.empty())
        {
            curr->right = s.top();
        }
        curr->left = nullptr;
    }
    display(root);
}

Node *dfsII(Node *curr, Node *lastVisited = nullptr)
{
    if (!curr)
        return lastVisited;
    if (lastVisited)
        lastVisited->right = curr;
    Node *left = curr->left;
    Node *right = curr->right;
    curr->left = curr->right = nullptr;
    Node *rightmost = dfsII(left, curr);
    return dfsII(right, rightmost);
}

Node *flattenII(Node *root)
{
    if (!root)
        return root;
    dfsII(root);
    return root;
}

void dfs(Node *root, Node *&pre)
{
    if (!root)
        return;
    if (pre)
        pre->right = root;
    pre = root;
    Node *left = root->left;
    Node *right = root->right;
    root->left = root->right = nullptr;
    dfs(left, pre);
    dfs(right, pre);
}

Node *flattenIV(Node *root)
{
    if (!root)
        return root;
    Node *pre = nullptr;
    dfs(root, pre);
    return root;
}

void flattenIII(Node *root)
{
    if (!root)
        return;
    Node *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            curr = curr->right;
        }
        else
        {
            Node *rightmost = curr->left;
            while (rightmost->right)
                rightmost = rightmost->right;
            rightmost->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
            curr = curr->right;
        }
    }
    display(root);
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
        // vi sv;
        // display(root, sv);
        // cout << endl;
        // flattenI(root);
        // cout << endl;
        flattenIV(root);
        display(root);
        cout << endl;
        // for (auto x : sv)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 15
// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1