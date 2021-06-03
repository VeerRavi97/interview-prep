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

struct state
{
    int level;
    int parent;
};

void dfs(Node *root, int x, int y, state &cousinX, state &cousinY, int level = 0, int parent = -1)
{
    if (!root)
        return;
    if (root->data == x)
    {
        cousinX.level = level;
        cousinX.parent = parent;
    }
    if (root->data == y)
    {
        cousinY.level = level;
        cousinY.parent = parent;
    }
    dfs(root->left, x, y, cousinX, cousinY, level + 1, root->data);
    dfs(root->right, x, y, cousinX, cousinY, level + 1, root->data);
}

bool isCousins(Node *root, int x, int y)
{
    state cousinX;
    state cousinY;
    dfs(root, x, y, cousinX, cousinY);
    if (cousinX.level == cousinY.level && cousinX.parent != cousinY.parent)
        return true;
    return false;
}

vector<int> solve(Node *root, int B)
{
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty() && !flag)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left && curr->left->data == B || curr->right && curr->right->data == B)
                flag = true;
            else
            {
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
    }
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        v.push_back(curr->data);
    }
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
        int x, y;
        cin >> x >> y;
        cout << isCousins(root, x, y) << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 15
// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1