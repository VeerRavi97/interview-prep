#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

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

int getHeight(Node *root, vvi &v)
{
    if (!root)
        return -1;
    int lh = getHeight(root->left, v);
    int rh = getHeight(root->right, v);
    int height = 1 + max(lh, rh);
    if (v.size() == height)
        v.push_back({});
    v[height].push_back(root->val);
    return height;
}

vector<vector<int>> findLeaves(Node *root)
{
    vector<vector<int>> res;
    getHeight(root, res);
    return res;
}

void display(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << endl;
    display(root->left);
    display(root->right);
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
        auto ans = findLeaves(root);
        for (auto &x : ans)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
/*
15
1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1
*/