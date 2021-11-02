#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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
struct State
{
    Node *node;
    int hd;
    int vd;
    State(Node *_node, int _hd, int _vd)
    {
        node = _node;
        hd = _hd;
        vd = _vd;
    }
};
void DiagonalOrder(Node *root, vi &v)
{
    if (!root)
        return;
    queue<pair<Node *, int>> q;
    int max_dist = INT_MIN;
    int min_dist = INT_MAX;
    q.push({root, 0});
    unordered_map<int, vector<int>> mp;
    while (!q.empty())
    {

        pair<Node *, int> curr = q.front();
        q.pop();
        max_dist = max(max_dist, curr.second);
        min_dist = min(min_dist, curr.second);
        vector<int> temp = mp[curr.second];
        temp.push_back(curr.first->data);
        mp[curr.second] = temp;
        if (curr.first->left)
        {
            q.push({curr.first->left, curr.second + 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, curr.second});
        }
    }
    for (int i = min_dist; i <= max_dist; i++)
    {
        for (auto x : mp[i])
            cout << x << " ";
        cout << endl;
    }
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int start_idx = 0;
        root = BuildTree(v, start_idx);
        vi sv; // serialized vector
        // display(root, sv);
        // cout << endl;
        // for (auto x : sv)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        DiagonalOrder(root, sv);
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