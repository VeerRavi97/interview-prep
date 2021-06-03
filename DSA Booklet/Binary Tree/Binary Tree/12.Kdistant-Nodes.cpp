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

void printAtKthLevel(Node *root, int k, vi &kv)
{
    if (!root)
        return;
    if (k == 0)
    {
        //cout << root->data << " ";
        kv.push_back(root->data);
        return;
    }
    printAtKthLevel(root->left, k - 1, kv);
    printAtKthLevel(root->right, k - 1, kv);
}

int helper(Node *root, int d, int k, vi &kv, int DIR_L = 0)
{
    if (d + 1 == k)
    {
        kv.push_back(root->data);
    }
    else
    {
        if (DIR_L)
            printAtKthLevel(root->left, k - 2 - d, kv);
        else
            printAtKthLevel(root->right, k - 2 - d, kv);
    }

    return 1 + d;
}

int recur(Node *root, Node *target, int k, vi &kv)
{
    if (!root)
        return -1;
    if (root == target)
    {
        printAtKthLevel(root, k, kv);
        return 0;
    }
    int ld = recur(root->left, target, k, kv);
    if (ld != -1)
        return helper(root, ld, k, kv);
    int rd = recur(root->right, target, k, kv);
    if (rd != -1)
        return helper(root, rd, k, kv, 1);

    return -1;
}

Node *search(Node *root, int target)
{
    if (!root)
        return nullptr;
    if (root->data == target)
        return root;
    Node *left = search(root->left, target);
    if (left)
        return left;
    Node *right = search(root->right, target);
    if (right)
        return right;
    return nullptr;
}

void distanceK(Node *root, int targett, int k, vi &kv)
{
    if (!root)
        return;
    Node *target = search(root, targett);
    recur(root, target, k, kv);
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
        int n, k, t;
        cin >> n >> k >> t;
        vi v(3 * n, 0);
        for (int i = 0; i < 2 * n + 1; i++)
            cin >> v[i];
        int start_idx = 0;
        root = BuildTree(v, start_idx);
        vi kv;
        // display(root, sv);
        // cout << endl;
        distanceK(root, t, k, kv);
        for (auto x : kv)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 31
// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1